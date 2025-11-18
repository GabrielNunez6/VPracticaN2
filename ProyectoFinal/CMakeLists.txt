cmake_minimum_required(VERSION 4.0)
project(ProyectoFinal C)

set(CMAKE_C_STANDARD 23)

add_executable(ProyectoFinal main.c
        aleatorio.c
        aleatorio.h
        domino.c
        domino.h
        jugador.c
        jugador.h
        turnos.c
        turnos.h
        ganador.c
        ganador.h
        registroPartida.c
        registroPartida.h
        MenuLucky20.c
        MenuLucky20.h
)
