"""
A recursive program to print the cummulative size of the entire directory
"""
from sys import argv
from os import path as os_path, listdir


def size(path):
    total = os_path.getsize(path)

    if os_path.isdir(path):
        for entry in listdir(path):
            total += size(os_path.join(path, entry))

    return total


if __name__ == '__main__':
    print("Size of {0} is {1:<7}".format(argv[1], size(argv[1])))

