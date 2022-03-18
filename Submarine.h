
#include <iostream>
#include <stack>
#include <string>
#include <algorithm>


class Submarine
{

 private:
  // return a line in a string
  auto ExtractLine (std::uint32_t& stPosition, std::string::iterator& iterator) {
    auto result = std::find(iterator, puzzle.end(), '\n');
    std::string::difference_type position = std::distance(iterator, result);
    auto subStr = puzzle.substr(stPosition, std::string::size_type(position));
    (result != puzzle.end()) ? iterator = ++result : iterator = puzzle.end();
    stPosition += std::uint32_t(position) + 1;
    return subStr;
  };

  // Is the chunck in the string is a opening or closing
  auto IsOpeningOrCloseingChunck (const char s) { return openingChunks.find(s); };

  // return next expected closing chunk
  auto FetchTheNextExpectedClosingChunk (std::stack<char>& stack) {
    stack.pop();
    return (stack.size() > 0) ? closingChunks[openingChunks.find(stack.top())] : char();
  };

  // If corruption occur keep a record of illegal character
  auto CorruptionOccur(std::uint32_t illegalCounts[], const char corruptChunk) {
    illegalCounts[closingChunks.find(corruptChunk)]++;
  };

  // puzzle string
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

  // puzzle iterator
  std::string::iterator puzzleIterator = puzzle.begin();

  // Opening chunks list
  std::string const openingChunks = "([{<";

  // closing chunk list
  std::string const closingChunks = ")]}>";

  // expected chunk
  char expectedClosingChunk{};

  // illegal character points
  std::uint32_t const points[4]{ 3, 57, 1197, 25137 };

  // record count for illegal characters
  std::uint32_t illegalCharacterCount[4]{};

  // starting position of charcter in the line
  std::uint32_t startPosition{};

 public:
  std::uint32_t SyntaxScoring();

};


