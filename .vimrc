set nocompatible
filetype off
set rtp+=~/.vim/bundle/vundle/
"call vundle#rc()
" let Vundle manage Vundle
" required!
"Bundle 'gmarik/vundle'
" The bundles you install will be listed here
filetype plugin indent on
" The rest of your config follows here
set cindent
set smartindent
set ruler
set tabstop=4
set shiftwidth=4
set number
set nuw=1
set hlsearch
set ignorecase
set showmatch
syntax on
set fencs=ucs-bom,utf-8,euc-kr.latin1
filetype on
set showmode
set ff=unix
set cul
if has("autocmd")
    au BufReadPost * if line("'\"") > 1 && line("'\"") <= line("$") | exe "normal! g'\"" | endif
endif
set background=dark
set t_Co=256
"ctags
"set tags=./tags
set tags=./tags,tags;$HOME
"cscope
if has('cscope')
    set csprg=/usr/bin/cscope
    set csto=0
    set cscopetag
    set nocsverb
    if filereadable("./cscope.out")
        cs add ./cscope.out
    endif
    set csverb
endif
nnoremap <silent> <F7> :TlistUpdate<CR>
nnoremap <silent> <F8> :TlistToggle<CR>
nnoremap <silent> <F9> :TlistSync<CR>
nmap <F5> :!cscope -b -q<CR>
            \:cs reset<CR>
let g:CSApprox_attr_map = { 'bold' : 'bold', 'italic' : '', 'sp' : '' }
cmap w!! w !sudo tee % >/dev/null
colorscheme PaperColor
