# XML Editor Project

Welcome to the **XML Editor** project! This program is designed to perform various operations on XML files, including formatting, conversion to JSON, minification, compression, and more. Additionally, it features social network analysis by representing user data as a graph structure.

## Features

### Level 1

1. **Check XML Consistency**
   - Validate an XML file for correctness and optionally fix errors.
2. **Format XML**
   - Prettify the XML file with proper indentation.
3. **Convert XML to JSON**
   - Convert the XML file into a JSON format.
4. **Minify XML**
   - Compress the XML file by removing unnecessary whitespace and newlines.
5. **Compress and Decompress XML/JSON**
   - Use data compression techniques to reduce file size and decompress it back to its original form.

### Level 2

1. **Social Network Representation**
   - Represent user data as a graph.
   - Visualize the graph connections in an output image file.
2. **Network Analysis**
   - Find the most active user (connected to the most users).
   - Identify the most influential user (user with the most followers).
   - Find mutual followers between specified users.
   - Suggest users to follow based on mutual connections.
3. **Post Search**
   - Search for posts containing a specific word or topic.

### Graph Visualization

- Visualize the social network graph using any third-party library.

### GUI Features

- Simple interface with buttons for all operations.
- View and edit the input XML.
- Display operation results.
- Save output to a new file.

---

## Project Structure

### Branches

- **`main`**: Contains the Command Line Interface (CLI).
- **`GUI_ALL_PROJECT`**: Contains the Graphical User Interface (GUI).

### Building the Project

1. Navigate to the `src` directory.
2. Run the following command:
   ```bash
   make
   ```

---

## Usage

### CLI Commands

Below are the available commands for the CLI version:

1. **Check XML Consistency**

   ```bash
   xml_editor verify -i input_file.xml -f -o output_file.xml
   ```

   - Validates the XML file.
   - If the file is invalid, displays errors and their line numbers.
   - With `-f` and `-o`, fixes errors and saves the corrected version.

2. **Format XML**

   ```bash
   xml_editor format -i input_file.xml -o output_file.xml
   ```

   - Formats the input XML file with proper indentation.

3. **Convert XML to JSON**

   ```bash
   xml_editor json -i input_file.xml -o output_file.json
   ```

   - Converts the XML file into JSON format.

4. **Minify XML**

   ```bash
   xml_editor mini -i input_file.xml -o output_file.xml
   ```

   - Removes whitespaces and compresses the XML file.

5. **Compress XML**

   ```bash
   xml_editor compress -i input_file.xml -o output_file.comp
   ```

   - Compresses the XML file into a smaller `.comp` file.

6. **Decompress XML**

   ```bash
   xml_editor decompress -i input_file.comp -o output_file.xml
   ```

   - Decompresses the `.comp` file back to XML.

8. **Network Analysis**

   - Most active user:
     ```bash
     xml_editor most_active -i input_file.xml
     ```
   - Most influential user:
     ```bash
     xml_editor most_influencer -i input_file.xml
     ```
   - Mutual followers:
     ```bash
     xml_editor mutual -i input_file.xml -ids 1,2,3
     ```
   - Suggested users to follow:
     ```bash
     xml_editor suggest -i input_file.xml -id 1
     ```

9. **Post Search**

   - Search by word:
     ```bash
     xml_editor search -w word -i input_file.xml
     ```
   - Search by topic:
     ```bash
     xml_editor search -t topic -i input_file.xml
     ```

---

## Contribution

Feel free to fork the repository, create issues, or submit pull requests for improvements and bug fixes.


