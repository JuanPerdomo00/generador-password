#!/usr/bin/python3
# -*- coding: utf-8 -*-
#
# Creador: Jakepy Perdomo <j4kyjak3@protonmail.com>
# Título: Generador de contraseña
# FechaCreación: 8-abr-22
#
# Código simple de un generador de contraseña.
# Copyright (c) 2022 Jakepy Perdomo <j4kyjak3@protonmail.com>.
# Comentarios bienvenidos.
#
# Permiso otorgado para uso y distribución no comercial siempre que
# este aviso de derechos de autor permanece intacto.
#
# Hay ejemplos de cómo usar este código en el README.md.
#
# Cual quier duda escribeme, o talvez este dormido jsjs.


from errno import ECHILD
from modules.Caracteres import Caracteres as Char
from modules.Colors import Colors
import random
import time

# constans
C = Colors()
OBJETOS = [
    Char().minus,
    Char().mayus,
    Char().nums,
    Char().char,
]


def banner():
    print(f"{C.green}[+] Generador password [+]{C.off}".center(50, "="), "\n")


def leingth_pass():
    try:
        n = int(
            input(f"\n{C.blue}[+] Ingrese la longitud de la password: {C.off}"))
        return n
    except ValueError as e:
        print(f"\n{C.red}Error, asegurate de haber ingresado un numero {C.off}")
        return exit(1)
    except KeyboardInterrupt as e:
        print(f"\n{C.red}bye...{C.off}")
        return exit(1)


def generate(n):
    all_caracteres = OBJETOS[0] + OBJETOS[1] + OBJETOS[2] + OBJETOS[3]
    passwords = []

    for _ in range(n):
        caracteres_ramdom = random.choice(all_caracteres)
        passwords.append(caracteres_ramdom)

    passwords = "".join(passwords)
    return passwords[::-1]


def main():
    banner()
    try:
        leingth_passwd = leingth_pass()
        password = generate(leingth_passwd)
        if len(password) >= 8:
            print(f"\n{C.green}[+] Generando...{C.off}\n")
            time.sleep(1.2)
            print(f"{C.green}[+] Su nueva password es: {C.red}{password}{C.off}")
        else:
            print(f"{C.green}La longitud tiene que ser minimo de 8 {C.off}")
            exit(0)
    except KeyboardInterrupt as e:
        print(f"\n{C.red}Bye ... {C.off}")
        return exit(1)
    except Exception:
        print(f"\n{C.red}Error {C.off}")


if __name__ == '__main__':
    main()
