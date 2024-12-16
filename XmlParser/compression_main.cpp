int main(int argc, char** argv) {
    string mode = argv[1];
    string input_file = argv[3];
    string output_file = argv[5];
    string content = read_file(input_file);
    string result;

    if (mode == "compress") {
        result = byte_pair_compress(content);
    }
    write_file(output_file, result);
    if (mode == "compress") {
        for (const auto& pair : mapping) {
            cout << pair.first << " -> " << pair.second << endl;
        }
    }
    return 0;
}