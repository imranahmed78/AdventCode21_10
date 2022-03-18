// Submarine.cpp : Defines the entry point for the application.
//

#include "Submarine.h"


std::uint32_t Submarine::SyntaxScoring()
{
  while (puzzleIterator != puzzle.end())
  {
    auto line = ExtractLine(startPosition, puzzleIterator);
    std::stack<char> stackOfOpenners{};
    expectedClosingChunk = {};
    for (auto chunk : line)
    {
      auto  result = IsOpeningOrCloseingChunck(chunk);
      if (result != std::string::npos) // opening
      {
        stackOfOpenners.push(chunk);
        expectedClosingChunk = closingChunks[result];
      }
      else// closing
      {
        if (chunk == expectedClosingChunk)  // expected closing
        {
          expectedClosingChunk = FetchTheNextExpectedClosingChunk(stackOfOpenners);
        }
        else {
          CorruptionOccur(illegalCharacterCount, chunk);
          break;
        }
      }
    }

  }


  return ([this]() {
    std::uint32_t score{};
    for (std::uint32_t i = 0; i < 4; i++) {
      score += points[i] * illegalCharacterCount[i];
    }
    return score;
  })();

}


