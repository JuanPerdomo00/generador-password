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


from modules.Caracteres import Caracteres as Char
from modules.Colors import Colors
from modules.Copy_Clip import Copy_Clip
from sys import argv
import random
import time
import argparse

__version__ = '0.0.1'

# constans form modules
C = Colors()

OBJETOS = [
    Char().minus,
    Char().mayus,
    Char().nums,
    Char().char,
]

########################################################################################
parser = argparse.ArgumentParser()
parser.add_argument('-v', '--version', action='version',
                    version=f'{__version__}', help="how program's version number")
parser.add_argument('-l', '--leng', type=int, help='password length >= 8')
parser.add_argument('-c', '--copy', type=str, default='y',
                    help='Copy password to clipboard [-c y or n]')

args = parser.parse_args()
########################################################################################


def banner():
    print(f"{C.green}[+] Generador password [+]{C.off}".center(50, "-"), "\n")
    print(f"{C.green}[+] GenPy By Jakepys [+]{C.off}".center(49, "-"), "\n")


def generate(n):
    try:
        all_caracteres = OBJETOS[0] + OBJETOS[1] + OBJETOS[2] + OBJETOS[3]
        passwords = []

        for _ in range(n):
            caracteres_ramdom = random.choice(all_caracteres)
            passwords.append(caracteres_ramdom)

        passwords = "".join(passwords)
        return passwords[::-1]
    except TypeError:
        pass


def main():
    banner()
    leingth_passwd = args.leng
    password = generate(leingth_passwd)
    try:
        if args.leng >= 8 and args.copy == "y".lower():
            pass_copy_clip = Copy_Clip()
            print(f"\n{C.green}[+] Generando...{C.off}\n")
            time.sleep(1)
            print(
                f"{C.green}[+] Su nueva password es: {C.red}{password}{C.off}")
            pass_copy_clip.copy_pass(password)

        elif args.leng >= 8 and args.copy == "n".lower():
            print(f"\n{C.green}[+] Generando...{C.off}\n")
            time.sleep(1)
            print(
                f"{C.green}[+] Su nueva password es: {C.red}{password}{C.off} \n")
            print(
                f"\n{C.red}[+]{C.off}{C.green} No copied to clitboard {C.off}")

        elif args.leng < 8 and args.copy == "y".lower() or args.copy == "n".lower():
            print(f"{C.green}La longitud tiene que ser minimo de 8 {C.off}")
            return exit(1)

        else:
            try:
                if int(args.copy):
                    print(f"{C.red}[-] Not number form args copy {C.off}")
                    print(
                        f"{C.red}[-] Use {argv[0]} -h or --help for more info {C.off}")
                    return exit(1)
            except ValueError:
                print(
                    f"{C.red}[-] Error, invalid  --> {C.green}{argv[4]}{C.off}{C.red} <-- {C.off}")
                print(
                    f"{C.red}[-] Use {argv[0]} -h or --help for more info {C.off}")
    except TypeError:
        print(
            f"{C.red}[-] Error use {argv[0]} arguments {C.green} -l [--leng] -c [--copy] -v [--version] or [-h] for more info{C.red}{C.off}")


if __name__ == '__main__':
    main()
