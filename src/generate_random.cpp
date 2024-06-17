#include <array>
#include <fstream>
#include <iostream>

#include <cstdlib>
#include <stdio.h>
#include <unistd.h> // in Linux

const int random_buf_len = 4096;
std::array<uint8_t, random_buf_len> buf;

// Generate random numbers and write them to a file
int generate_random_numbers(const char *filename, long bytes_count) {

  FILE *rfp = nullptr;
  FILE *wfp = nullptr;

  if (!bytes_count) {
    return -1;
  }

  if (!(rfp = fopen("/dev/urandom", "rb"))) {
    return -1;
  }

  if (!(wfp = fopen(filename, "wb"))) {
    return -1;
  }

  do {
    if (fread(buf.data(), 1, random_buf_len, rfp) != random_buf_len) {
      fclose(rfp);
      return -1;
    }

    if(fwrite(buf.data(), 1, random_buf_len, wfp) != random_buf_len) {
      fclose(wfp);
      return -1;
    }
    bytes_count -= random_buf_len;
  } while (bytes_count >= 0);

  fclose(rfp);
  fclose(wfp);
  return 1;
}

int main(int argc, const char **argv) {

    if (argc < 3) {
        std::cout << "error, need more argv" << std::endl;
    }

    int bits_stream_length = std::atoi(argv[1]);
    int streams_count = std::atoi(argv[2]);

    long bytes_count = bits_stream_length * streams_count / 8;

    if (generate_random_numbers("test.dat", bytes_count) <= 0) {
        std::cout << "error, generate wrong" << std::endl;
    }
    return 0;
}