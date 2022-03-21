// SyntaxScoring.cpp : Defines the entry point for the application.
//

#include "SyntaxScoring.h"

SyntaxScoring::SyntaxScoring(std::string& puzzleRef):
puzzle(puzzleRef)
{}

std::tuple<std::uint32_t, std::uint64_t> SyntaxScoring::ChunkScoring()
{
  std::uint32_t count{};
  while (puzzleIterator != puzzle.end())
  {
    auto line = ExtractLine(startPosition, puzzleIterator);
	//std::cout << ++count << "  " << line << std::endl;
    std::stack<char> stackOfOpenners{};
    expectedClosingChunk = {};

    auto isCorrupted = false;
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
          isCorrupted = true;
          break;
        }
      }
    }

    if(!isCorrupted)
    {
      InCompleteLinesScoring(stackOfOpenners);
    }

  }

  std::cout << "Done Scoring  " << std::endl;

  return ([this]() {
    std::uint32_t score{};
    std::uint64_t middleScore{};
    for (std::uint32_t i = 0; i < 4; i++) {
      score += points[0][i] * illegalCharacterCount[i];
    }

    std::sort(inCompleteLinesScores.begin(), inCompleteLinesScores.end());
    inCompleteLinesScores.empty() ? middleScore = 0 : middleScore = inCompleteLinesScores[inCompleteLinesScores.size()/2] ;
    return std::make_tuple(score, middleScore);
  })();

}


