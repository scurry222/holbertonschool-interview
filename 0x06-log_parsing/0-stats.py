#!/usr/bin/python3
''' Module that reads stdin line by line and computes metrics '''

if __name__ == '__main__':
    import sys

    file_size, count = 0, 0
    codes = {200: 0, 301: 0, 400: 0, 401: 0, 403: 0, 404: 0, 405: 0, 500: 0}

    def print_codes(codes, file_size):
        ''' Print all status codes generated so far '''
        print("File size: {}".format(file_size))
        for k in sorted(codes.keys()):
            if codes[k]:
                print("{}: {}".format(k, codes[k]))
    try:
        for line in sys.stdin:
            try:
                data = line.split()
                status_code = int(data[-2])

                if status_code in codes:
                    codes[status_code] += 1
            except BaseException:
                pass
            try:
                file_size += int(data[-1])
            except BaseException:
                pass

            count += 1
            if count % 10 == 0:
                print_codes(codes, file_size)

    except KeyboardInterrupt:
        print_codes(codes, file_size)
        raise

    print_codes(codes, file_size)
