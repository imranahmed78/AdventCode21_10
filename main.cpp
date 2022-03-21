#include "SyntaxScoring.h"

int main() {

  std::string puzzle = {
      "[({(<(())[]>[[{[]{<()<>>\n"
      "[(()[<>])]({[<{<<[]>>(\n"
      "{([(<{}[<>[]}>{[]{[(<()>\n"
      "(((({<>}<{<{<>}{[]{[]{}\n"
      "[[<[([]))<([[{}[[()]]]\n"
      "[{[{({}]{}}([{[{{{}}([]\n"
      "{<[[]]>}<{[{[{[]{()[[[]\n"
      "[<(<(<(<{}))><([]([]()\n"
      "<{([([[(<>()){}]>(<<{{\n"
      "<{([{{}}[<[[[<>{}]]]>[]]"
  };

  std::FILE *file = std::fopen("../puzzle.txt", "r");

  if(!file)
  {
    std::cout << " File does exist hard coded puzzle will be consider " << std::endl;
    for(auto s:puzzle)
    {
      std::cout<< s;
    }
    std::cout << std::endl;
  }
  else
  {
    std::cout << " File found " << std::endl;
    puzzle.clear();

    fseek(file, 0, SEEK_END);

    // get current file position which is end from seek
    auto size = ftell(file);

    // allocate string space and set length
    puzzle.resize(static_cast<unsigned long>(size));

    // go back to beginning of file for read
    rewind(file);

    // read 1*size bytes from sfile into ss
    fread(&puzzle[0], 1, static_cast<size_t>(size), file);

    // close the file
    fclose(file);
  }

  std::cout << " Start Scoring  " <<  " puzzle  size  "<<  puzzle.size() <<  std::endl;
  SyntaxScoring  syntaxScoring{puzzle};
  auto  result = syntaxScoring.ChunkScoring();
  std::cout << " Illegal Charcter  Score is " << std::get<0>(result)
            << " Completion Score is  " << std::get<1>(result) << std::endl;
  return 0;
}


