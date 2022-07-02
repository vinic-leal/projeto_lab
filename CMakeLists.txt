cmake_minimum_required(VERSION 3.22)
project(projeto_lab C)

set(CMAKE_C_STANDARD 11)

add_executable(projeto_lab
        projeto.c MenuVenda.c MenuVenda.h MenuCliente.c MenuCliente.h MenuProduto.c MenuProduto.h projeto.h)
