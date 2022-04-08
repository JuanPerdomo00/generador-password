#!/usr/bin/python3

# Generador de password simple
import caracteres as car 
import random
import time

def banner():
    print("="*36)
    print("[+] Generador password by jakepy [+]")
    print("="*36)


def leingth_pass():
    n = int(input("\n[+] Ingrese la longitud de la password: "))
    return n


def generate(n):
    all_caracteres = car.CHARS + car.MAYUS + car.MINUS + car.NUMS

    passwords = []

    for i in range(n):
        caracteres_ramdom = random.choice(all_caracteres)
        passwords.append(caracteres_ramdom)

    passwords = "".join(passwords)
    return passwords

def main():
    banner()
    password = generate(leingth_pass())
    print("\n[+] Generando...\n")
    time.sleep(1.6)
    print(f"[+] Su nueva password es: {password}")

if __name__ == '__main__':
    main()
