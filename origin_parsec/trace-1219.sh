#!/bin/bash

if [ "$EUID" -ne 0 ]
then
	echo "run as root"
	exit
fi

CALLEE_DIR=`dirname $0`
pushd $CALLEE_DIR > /dev/null


DAP_DIR=../dap-exp
RES_DIR=../result-exp
#TRACE_DIR=/sys/kernel/debug/mapia
TRACE_DIR=/home/yjsohn/debug/mapia

run_parallel () {
	local command=$1
	local name=$2
	local keyword=$3

	echo 3 > /proc/sys/vm/drop_caches
	sleep 2
	echo "$name: Tracing data access pattern.."

	eval "$command |& tee $RES_DIR/$name-daptrace.out 2>&1" &

	while true
	do
		pids=`pgrep -f $keyword`
		nr_pids=`echo $pids | wc -w`
		if [ $nr_pids -eq 1 ]
		then
			break
		fi
	done
	echo $pids > $TRACE_DIR/pids
	echo on > $TRACE_DIR/tracing_on

	# Wait until the program finishes 
	while true
	do
		pids=`pgrep -f $keyword`
		nr_pids=`echo $pids | wc -w`
		if [ $nr_pids -eq 0 ]
		then
			break
		fi
		sleep 10
	done
	echo off > $TRACE_DIR/tracing_on

	#mv /mapia.res.bin $DAP_DIR/$name-0114-0.data
}

mkdir $DAP_DIR
mkdir $RES_DIR

echo off > $TRACE_DIR/tracing_on
#echo "1000000 100000000 1000000000 10 1000 /mapia.res.bin" > $TRACE_DIR/attrs
echo "1000000 100000000 1000000000 15000 15000 /mapia.res.bin" > $TRACE_DIR/attrs
rm /mapia.res.bin

pushd /home/yjsohn/origin_parsec/parsec3_on_ubuntu/parsec-3.0 > /dev/null
source env.sh
popd > /dev/null

group="splash2x"
workloads=("ocean_ncp")
nr_repeat=1
for (( i = 0; i < ${#workloads[@]}; i++ ))
do
	cmd="taskset -c 0 parsecmgmt -a run -p $group.${workloads[i]} -i native -n 1" 
	name="$group.${workloads[i]}"
	keyword="bin/${workloads[i]}"

	run_parallel "$cmd" "$name" "$keyword"
done

popd > /dev/null
