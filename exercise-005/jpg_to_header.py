from PIL import Image
import sys
import os

def convert_image_to_header(input_path, output_path):
    # Open the image file
    img = Image.open(input_path)
    img = img.convert("RGB")  # Convert to RGB mode
    img_data = img.tobytes()  # Get the raw bytes of the image

    # Prepare the header content
    variable_name = os.path.splitext(os.path.basename(input_path))[0].replace("-", "_")
    header_content = f"// Generated from {input_path}\n\n"
    header_content += f"const unsigned char {variable_name}[] = {{\n"
    for i, byte in enumerate(img_data):
        header_content += f"0x{byte:02x}, "
        if (i + 1) % 12 == 0:
            header_content += "\n"
    header_content = header_content.rstrip(", \n")  # Remove last comma
    header_content += "\n};\n"
    header_content += f"const unsigned int {variable_name}_width = {img.width};\n"
    header_content += f"const unsigned int {variable_name}_height = {img.height};\n"

    # Write to the output file
    with open(output_path, "w") as header_file:
        header_file.write(header_content)
    print(f"Header file created at {output_path}")

if __name__ == "__main__":
    if len(sys.argv) != 3:
        print("Usage: python jpg_to_header.py <input.jpg> <output.h>")
        sys.exit(1)

    input_file = sys.argv[1]
    output_file = sys.argv[2]
    convert_image_to_header(input_file, output_file)
