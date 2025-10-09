ofstream out("copy_binary.pgm",ios::binary);
out << type << "\n";
out << comment << "\n";
out << width << " " << height << "\n";
out << maxval << "\n";
out.write((char*) pixels, width * height);