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

  std::FILE * file = std::fopen("../puzzle.txt", "r");

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

  SyntaxScoring  syntaxScoring{puzzle};
  std::cout  <<  " Score is " << syntaxScoring.IllegalCharacterScoring() << std::endl;
  return 0;
}


