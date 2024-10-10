# DumbBuster
DumbBuster is a simple directory brute-force tool written in C++. It attempts to discover hidden directories and files on a target web server by iterating through a wordlist of potential paths.


## Features

- **Simple and Fast**: Quickly scans for valid paths on a target domain.
- **Colored Output**: Highlights valid paths in green and invalid paths in red for better visibility.
- **Custom Wordlists**: Supports user-provided wordlists for flexible scanning.
- **HTTP and HTTPS Support**: Automatically prepends `http://` if no scheme is provided.

## Table of Contents

- [Requirements](#requirements)
- [Installation](#installation)
- [Usage](#usage)
- [Example](#example)
- [Compilation Issues](#compilation-issues)
- [Contributing](#contributing)
- [License](#license)
- [Disclaimer](#disclaimer)

## Requirements

- **C++17** or higher
- [CPR](https://github.com/libcpr/cpr) - C++ Requests: Curl for People
- [libcurl](https://curl.se/libcurl/)
- [zlib](https://zlib.net/)
- **OpenSSL** libraries (`libssl`, `libcrypto`)

## Installation

### 1. Install Dependencies

#### Using vcpkg (Recommended)

```bash
# Clone vcpkg if you haven't already
git clone https://github.com/microsoft/vcpkg.git
cd vcpkg
./bootstrap-vcpkg.sh

# Install dependencies
./vcpkg install cpr curl zlib openssl
```

#### Using Package Managers

For Debian/Ubuntu:

```bash
sudo apt-get update
sudo apt-get install build-essential libcurl4-openssl-dev libssl-dev zlib1g-dev
```

### 2. Clone the Repository

```bash
git clone https://github.com/yourusername/dumbbuster.git
cd dumbbuster
```

### 3. Compile the Program

```bash
g++ dumbbuster.cpp -o dumbbuster \
    -I path_to_vcpkg/installed/x64-linux/include \
    -L path_to_vcpkg/installed/x64-linux/lib \
    -lcpr -lcurl -lz -lssl -lcrypto \
    -std=c++17
```

**Note**: Replace `path_to_vcpkg` with the actual path to your vcpkg installation. If you used system package managers to install dependencies, you might only need:

```bash
g++ dumbbuster.cpp -o dumbbuster -lcpr -lcurl -lz -lssl -lcrypto -std=c++17
```

## Usage

1. **Prepare a Wordlist**

   Create a text file containing potential directory and file names to test against the target server. Each line should contain one path, for example:

   ```
   /admin/
   /login/
   /dashboard/
   /secret/
   ```

2. **Run DumbBuster**

   ```bash
   ./dumbbuster
   ```

3. **Follow the Prompts**

   - Enter the target domain when prompted.
   - Enter the path to your wordlist file when prompted.

## Example

```bash
$ ./dumbbuster
Enter your target domain: example.com
Enter path to wordlist: wordlist.txt
http://example.com/admin/ doesn't exist
http://example.com/login/ is a valid path!
http://example.com/dashboard/ doesn't exist
http://example.com/secret/ doesn't exist
```

- **Valid paths** are displayed in **green**.
- **Invalid paths** are displayed in **red**.
![DumbBuster Demo](/buster.png)
## Compilation Issues

If you encounter linker errors related to missing libraries (e.g., `undefined reference to 'curl_easy_init'`), ensure that you have all the required dependencies installed and linked correctly.

**Common Solutions**:

- **Link Order**: The order of linked libraries matters. Libraries that depend on others should come before them.

  ```bash
  -lcpr -lcurl -lz -lssl -lcrypto
  ```

- **Missing Dependencies**: Install missing libraries via your package manager or `vcpkg`.

- **C++ Standard**: Ensure you're compiling with `-std=c++17` or higher.

## Contributing

Contributions are welcome! Please open an issue or submit a pull request on GitHub.

1. Fork the repository.
2. Create a new branch: `git checkout -b feature/your-feature-name`.
3. Commit your changes: `git commit -am 'Add some feature'`.
4. Push to the branch: `git push origin feature/your-feature-name`.
5. Open a pull request.

## License

This project is licensed under the [MIT License](LICENSE).

## Disclaimer

This tool is intended for educational purposes only. Unauthorized use on servers without permission is illegal and unethical. Use this tool responsibly.
