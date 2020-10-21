#include "board.h"
#include "ai.h"

int main()
{
    Board board;
    AI ai;

    std::cout << "--------------------\n\nConnect-Four MiniMax\n\n--------------------\n\n";

    int maxDepth;
    while (1)
    {
        char skill;
        std::cout << "Difficulty Level [h]: hard | [m]: medium | [e]: easy | [n]: no limit: ";
        std::cin >> skill;

        if (skill == 'h')
        {
            maxDepth = 9;
            break;
        }
        else if (skill == 'm')
        {
            maxDepth = 5;
            break;
        }
        else if (skill == 'e')
        {
            maxDepth = 3;
            break;
        }
        else if (skill == 'n')
        {
            maxDepth = 41;
            break;
        }
    }

    while (1)
    {
        board.printBoard();

        int move;
        std::cout << "Enter Move: ";
        std::cin >> move;
        board.dropDisk(move - 1, HUMAN);
        board.printBoard();

        if (board.scoreBoard() == HUMAN_WIN)
        {
            std::cout << "You Win!" << std::endl;
            break;
        }

        std::cout << "Computer is comtemplating its move..."
                  << std::endl;
        Move compMove = ai.minimax(board, true, maxDepth, COMP, ALPHA, BETA);
        board.dropDisk(compMove.move, COMP);

        if (board.scoreBoard() == COMP_WIN)
        {
            board.printBoard();
            std::cout << "Computer Wins..." << std::endl;
            break;
        }
    }

    return 0;
}