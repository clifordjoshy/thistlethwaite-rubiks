#include<array>
#include<vector>
#include<cstdint>

typedef std::array<uint_fast32_t, 6> FaceArray;

enum Color{WHITE, YELLOW, BLUE, GREEN, RED, ORANGE};

//two non affecting moves are separated by 2 ie U + 2 -> D
//all '2' moves are odd. ie U2 is 1, D2 is 3
//all single moves are even
//NONE for passing to DFS start
enum Move{U = 0, U2 = 1, D = 2, D2 = 3, F = 10, F2 = 11, B = 12, B2 = 13, L = 20, L2 = 21, R = 22, R2 = 23, NONE = 50};

/* rubiks cube should be read as 

            a b c  <--U
            d e f
            g h i
            _____
    a b c | a b c | a b c | a b c
    d e f | d e f | d e f | d e f
    g h i | g h i | g h i | g h i
            _____
            a b c
            d e f
            g h i

*/

/* rubiks cube is stored as 

            0 1 2  <--U
            7   3
            6 5 4
            _____
    0 1 2 | 0 1 2 | 0 1 2 | 0 1 2
    7   3 | 7   3 | 7   3 | 7   3
    6 5 4 | 6 5 4 | 6 5 4 | 6 5 4
            _____
            0 1 2
            7   3
            6 5 4

*/

void doMove(const Move &move, FaceArray &faces);
void doMoveList(FaceArray &faces, const std::vector<Move> &moveList);

void initialiseSolver(const Color centres[6]);

std::vector<Move> getStage1Moves(const FaceArray &faces, const Color centres[6]);
std::vector<Move> getStage2Moves(const FaceArray &faces, const Color centres[6]);
std::vector<Move> getStage3Moves(const FaceArray &faces, const Color centres[6]);
std::vector<Move> getStage4Moves(const FaceArray &faces, const Color centres[6]);

bool isAllEdgesGood(const FaceArray &faces, const Color centres[6]);
bool isStage2Goal(const FaceArray &faces, const Color centres[6]);
bool isStage3Goal(const FaceArray &faces, const Color centres[6]);
bool isSolved(const FaceArray &faces, const Color centres[6]);