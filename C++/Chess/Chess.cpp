#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool does_exist(const vector<vector<char>> &v, char item)
{
    vector<vector<char>>::const_iterator row;

    for (row = v.begin(); row != v.end(); row++)
    {
        if (find(row->begin(), row->end(), item) != row->end())
        {
            return true;
        }
    }

    return false;
}

bool pawn(int x, int y, int tarx, int tary, vector<vector<char>> board)
{
    if (tary == y + 2 && tarx == x && board[tary][tarx] == ' ')
    {
        if (board[1][x] == 'p')
        {
            return true;
        }
    }
    else if (tary == y + 1 && tarx == x && board[tary][tarx] == ' ')
    {
        return true;
    }
    else if (tary == y + 1)
    {
        if (tarx == x + 1 || tarx == x - 1)
        {
            return true;
        }
    }

    if (tary == y + - 2 && tarx == x && board[tary][tarx] == ' ')
    {
        if (board[6][x] == 'P')
        {
            return true;
        }
    }
    else if (tary == y - 1 && tarx == x && board[tary][tarx] == ' ')
    {
        return true;
    }
    else if (tary == y - 1)
    {
        if (tarx == x + 1 || tarx == x - 1)
        {
            return true;
        }
    }

    return false;
}

bool rook(int x, int y, int tarx, int tary, vector<vector<char>> board)
{
    if (tary != y && tarx == x)
    {
        for (auto i = board.end(); i < board.begin(); ++i)
        {
            if (i == board[y])
            {

            }
        }

        return true;
    }
    else if (tary == y && tarx != x)
    {
        return true;
    }

    return false;
}

bool knight(int x, int y, int tarx, int tary)
{
    if (tary == y + 2)
    {
        if (tarx == x + 1 || tarx == x - 1)
        {
            return true;
        }
    }
    else if (tary == y - 2)
    {
        if (tarx == x + 1 || tarx == x - 1)
        {
            return true;
        }
    }
    else if (tarx == x + 2)
    {
        if (tary == y + 1 || tary == y - 1)
        {
            return true;
        }
    }
    else if (tarx == x - 2)
    {
        if (tary == y + 1 || tary == y - 1)
        {
            return true;
        }
    }

    return false;
}

bool bishop(int x, int y, int tarx, int tary, vector<vector<char>> board)
{
    if (abs(tary - y) == abs(tarx - x))
    {
        return true;
    }

    return false;
}

bool king(int x, int y, int tarx, int tary)
{
    if (tary == y + 1)
    {
        if (tarx == x + 1)
        {
            return true;
        }
        else if (tarx == x - 1)
        {
            return true;
        }
    }
    else if (tary == y - 1)
    {
        if (tarx == x + 1)
        {
            return true;
        }
        else if (tarx == x - 1)
        {
            return true;
        }
    }

    if (tary == y + 1 && tarx == x)
    {
        return true;
    }
    else if (tary == y - 1 && tarx == x)
    {
        return true;
    }
    else if (tarx == x + 1 && tary == y)
    {
        return true;
    }
    else if (tarx == x - 1 && tary == y)
    {
        return true;
    }

    return false;
}

bool queen(int x, int y, int tarx, int tary, vector<vector<char>> board)
{
    if (tary != y && tarx == x)
    {
        return true;
    }
    else if (tary == y && tarx != x)
    {
        return true;
    }

    if (abs(tary - y) == abs(tarx - x))
    {
        return true;
    }

    return false;
}

int main()
{
    vector<vector<char>> board{{'r', 'n', 'b', 'k', 'q', 'b', 'n', 'r'},
                               {'p', 'p', 'p', 'p', 'p', 'p', 'p', 'p'},
                               {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                               {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                               {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                               {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                               {'P', 'P', 'P', 'P', 'P', 'P', 'P', 'P'},
                               {'R', 'N', 'B', 'K', 'Q', 'B', 'N', 'R'}};
    string coords;
    string toMove;
    int num{};
    int let{};
    int tarNum{};
    int tarLet{};
    int move = 0;
    cout << "Lowercase is black" << endl;

    while (does_exist(board, 'K') && does_exist(board, 'k'))
    {
        for (size_t i = 0; i < board.size(); ++i)
        {
            cout << (i + 1) << "    ";

            for (auto j = board[i].begin(); j < board[i].end(); ++j)
            {
                cout << "| " << * j << " ";
            }

            cout << endl;
            cout << "       -   -   -   -   -   -   -   -  " << endl;

            if (i == board.size() - 1)
            {
                cout << endl;
                cout << "       a   b   c   d   e   f   g   h  " << endl;
            }
        }

        cout << "Select coordinates (ex. e4): ";
        cin >> coords;

        for (auto iter = coords.begin(); iter < coords.end(); ++iter)
        {
            if (coords.length() > 2)
            {
                cerr << "ERROR";
                break;
            }

            if (*iter >= 97 && *iter <= 104)
            {
                let = *iter - 97;
            }
            else if (*iter >= 49 && *iter <= 56)
            {
                num = *iter - 49;
            }
        }

        cout << "Select target coordinates (ex. b8): ";
        cin >> toMove;

        for (auto iter = toMove.begin(); iter < toMove.end(); ++iter)
        {
            if (toMove.length() > 2)
            {
                cerr << "ERROR";
                break;
            }

            if (*iter >= 97 && *iter <= 104)
            {
                tarLet = *iter - 97;
            }
            else if (*iter >= 49 && *iter <= 56)
            {
                tarNum = *iter - 49;
            }
        }

        if (move % 2 != 0)
        {
            switch (board[num][let])
            {
                case 'p':

                    if (pawn(let, num, tarLet, tarNum, board))
                    {
                        board[num][let] = ' ';
                        board[tarNum][tarLet] = 'p';
                    }
                    else
                    {
                        cerr << "ERROR" << endl;
                        break;
                    }

                    ++move;
                    continue;

                case 'r':

                    if (rook(let, num, tarLet, tarNum, board))
                    {
                        board[num][let] = ' ';
                        board[tarNum][tarLet] = 'r';
                    }
                    else
                    {
                        cerr << "ERROR" << endl;
                        break;
                    }

                    ++move;
                    continue;

                case 'n':

                    if (knight(let, num, tarLet, tarNum))
                    {
                        board[num][let] = ' ';
                        board[tarNum][tarLet] = 'n';
                    }
                    else
                    {
                        cerr << "ERROR" << endl;
                        break;
                    }

                    ++move;
                    continue;

                case 'b':

                    if (bishop(let, num, tarLet, tarNum, board))
                    {
                        board[num][let] = ' ';
                        board[tarNum][tarLet] = 'b';
                    }
                    else
                    {
                        cerr << "ERROR" << endl;
                        break;
                    }

                    ++move;
                    continue;

                case 'k':

                    if (king(let, num, tarLet, tarNum))
                    {
                        board[num][let] = ' ';
                        board[tarNum][tarLet] = 'k';
                    }
                    else
                    {
                        cerr << "ERROR" << endl;
                        break;
                    }

                    ++move;
                    continue;

                case 'q':

                    if (queen(let, num, tarLet, tarNum, board))
                    {
                        board[num][let] = ' ';
                        board[tarNum][tarLet] = 'q';
                    }
                    else
                    {
                        cerr << "ERROR" << endl;
                        break;
                    }

                    ++move;
                    continue;

                default:
                    cerr << "ERROR" << endl;
                    break;
            }
        }
        else
        {
            switch (board[num][let])
            {
                case 'P':

                    if (pawn(let, num, tarLet, tarNum, board))
                    {
                        board[num][let] = ' ';
                        board[tarNum][tarLet] = 'P';
                    }
                    else
                    {
                        cerr << "ERROR" << endl;
                        break;
                    }

                    ++move;
                    continue;

                case 'R':

                    if (rook(let, num, tarLet, tarNum, board))
                    {
                        board[num][let] = ' ';
                        board[tarNum][tarLet] = 'R';
                    }
                    else
                    {
                        cerr << "ERROR" << endl;
                        break;
                    }

                    ++move;
                    continue;

                case 'N':

                    if (knight(let, num, tarLet, tarNum))
                    {
                        board[num][let] = ' ';
                        board[tarNum][tarLet] = 'N';
                    }
                    else
                    {
                        cerr << "ERROR" << endl;
                        break;
                    }

                    ++move;
                    continue;

                case 'B':

                    if (bishop(let, num, tarLet, tarNum, board))
                    {
                        board[num][let] = ' ';
                        board[tarNum][tarLet] = 'B';
                    }
                    else
                    {
                        cerr << "ERROR" << endl;
                        break;
                    }

                    ++move;
                    continue;

                case 'K':

                    if (king(let, num, tarLet, tarNum))
                    {
                        board[num][let] = ' ';
                        board[tarNum][tarLet] = 'K';
                    }
                    else
                    {
                        cerr << "ERROR" << endl;
                        break;
                    }

                    ++move;
                    continue;

                case 'Q':

                    if (queen(let, num, tarLet, tarNum, board))
                    {
                        board[num][let] = ' ';
                        board[tarNum][tarLet] = 'Q';
                    }
                    else
                    {
                        cerr << "ERROR" << endl;
                        break;
                    }

                    ++move;
                    continue;

                default:
                    cerr << "ERROR" << endl;
                    break;
            }
        }
    }

    cout << "Mate! You took " << move << " moves";
}