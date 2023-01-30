#!/usr/bin/python3

import os
import time


def banner() -> None:
    """
    banner
    """
    print(" installing password generator ".center(50, "#"))


def clear() -> None:
    """
    detects the operating system and cleans the terminal
    """
    os.system("clear")


def move_binaries(destine_path: str, usr_bin_path: str) -> None:
    """
    copies the files and pastes them into the /usr/bin path so you can run it as a system command
    """
    print("[*] prepare files on computer: %s " % os.environ["HOSTNAME"])
    print("-> copying modules to /usr/bin")
    os.system("sudo cp -r %s/modules %s" % (destine_path, usr_bin_path))
    time.sleep(2.1)
    os.system("mv %s/gen.py genpy && cp genpy %s" %
              (destine_path, usr_bin_path))


def download_dependencies(file_path: str) -> None:
    """
    iterate over the requirements.txt file and run the pip command to install the dependencies. If there were more than one dependency, it would be installed from 0 to ... number of packages
    """
    list_dependences = [i for i in open(file_path).readlines()]

    for i in list_dependences:
        try:
            print("installing %s" % i)
            os.system("pip3 install %s" % i)
        except KeyboardInterrupt as _:
            clear()
            print("canceling installation")
            exit(1)
    else:
        clear()
        print("[*] Good instalations")
        time.sleep(2.1)
        clear()
        banner()
        # move_binaries(os.environ["PWD"], "/usr/bin")


def main() -> None:
    """
    calls the functions and executes everything
    """
    PWD: str = os.environ["PWD"] + "/requirements.txt"
    clear()
    banner()
    download_dependencies(PWD)

    print("""
    Installation complete, to verify if it was installed correctly run the command: genpy --version
    """)
    exit(0)


if __name__ == "__main__":
    main()
