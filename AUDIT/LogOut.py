import hashlib
import sys

def sha512_hash(data):
    return hashlib.sha512(data.encode("utf-8")).hexdigest()

def verify_sha512(data, expected_hash):
    actual_hash = sha512_hash(data)
    return actual_hash == expected_hash


def main():
    if len(sys.argv) < 3:
        print("Invalid arguments.")
        return
      
    operation = sys.argv[1]
    data = sys.argv[2]

    if operation == "hash":
        print(sha512_hash(data))

      elif operation == "verify":
        expected_hash = sys.argv[3]

        if verify_sha512(data, expected_hash):
            print("VALID")
        else:
            print("INVALID")


if __name__ == "__main__":
    main()


  
