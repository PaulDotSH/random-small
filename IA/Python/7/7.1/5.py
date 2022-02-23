def read_numbers(in_file):
    return [int(x) for x in open(in_file, 'r').read().split(' ')]
