import crypt
import hashlib


def sum_to_n(n, size, limit=None):
    """
    List of positive integers that add up to n
    """
    if size == 1:
        yield [n]
        return
    if limit is None:
        limit = n

    start = (n + size - 1) // size
    stop = min(limit, n - size + 1) + 1
    for i in range(start, stop):
        for tail in sum_to_n(n - i, size - 1, i):
            yield [i] + tail


def main():
    welcome = """
    Welcome to Roland's super awesome mathdoku helper.

    8888888b. 888    888
    888   Y88b888    888
    888    888888    888
    888   d88P8888888888
    8888888P" 888    888
    888 T88b  888    888
    888  T88b 888    888
    888   T88b888    888
    """

    print welcome

    goal = int(raw_input("What is the goal number? "))
    spots = int(raw_input("How many spots? "))
    limit = int(raw_input("Biggest number? "))

    exclude = list(raw_input("Numbers to exclude? "))
    exclude = map(int, exclude)

    for partition in sum_to_n(goal, spots, limit):
        if not set(partition) & set(exclude):
            if len(partition) != len(set(partition)):
                print partition, '\t\t**duplicates'
            else:
                print partition

if __name__ == "__main__":
    main()
