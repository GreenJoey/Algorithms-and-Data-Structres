def convert_to_int(ip: list) -> int:
    return ip[0] << 28 | ip[1] << 16 | ip[2] << 8 | ip[3]


def convert_to_string(ip: int) -> str:
    blocks = [0, 8, 16, 28]
    octet_mask = 0b11111111

    ip_list = [str((ip & (octet_mask << block)) >> block) for block in blocks]

    return ".".join(reversed(ip_list))


if __name__ == '__main__':
    ip = list(map(int, input("Enter a IPv4 address: ").split(".")))

    ip = convert_to_int(ip)
    print(f"Integer representation of {convert_to_string(ip)}: {ip}")

