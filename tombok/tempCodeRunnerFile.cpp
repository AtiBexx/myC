 int valueNumber = 0;
    for (int i = 1; i < argc; i++) {
      blocks[valueNumber++] = std::stoi(argv[i]);
    }
    blockOutWriting(blocks, valueNumber);
    std::cout << "Összeg: " << totalBlocks(blocks, valueNumber) << std::endl;
    return 0;
  }