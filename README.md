# FunnyJsonExplorer
Funny JSON Explorer (**FJE**) is a command line interface tool for visualizing JSON files

## Build
```bash
cd path/to/this/repo
cmake .
make
```

## Usage
```
Usage: ./fje [OPTIONS]

Options:
  -h,--help                   Print this help message and exit
  -f TEXT:FILE REQUIRED       The JSON file to be visualized
  -s TEXT:{tree,rectangle} [tree] 
                              Choose an output style
  -i TEXT:FILE                Path to the icon family configuration file
```

## Used third-party tools
- [nlohmann/json](https://github.com/nlohmann/json): Load JSON file
- [CLI11](https://github.com/CLIUtils/CLI11): Parse command line options
