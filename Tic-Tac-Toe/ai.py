__author__ = 'Roland'

class Ai():
    """
    Artificial intelligence for a tic-tac-toe game.
    Follows algorithm:
        1. Win: If the player has two in a row, they can place a third to get three in a row.
        2. Block: If the [opponent] has two in a row, the player must play the third themself to block the opponent.
        3. Fork: Create an opportunity where the player has two threats to win (two non-blocked lines of 2).
        4. Blocking an opponent's fork:
        5. Option 1: The player should create two in a row to force the opponent into defending, as long as it doesn't result in them creating a fork. For example, if "X" has a corner, "O" has the center, and "X" has the opposite corner as well, "O" must not play a corner in order to win. (Playing a corner in this scenario creates a fork for "X" to win.)
        6. Option 2: If there is a configuration where the opponent can fork, the player should block that fork.
        7. Center: A player marks the center. (If it is the first move of the game, playing on a corner gives "O" more opportunities to make a mistake and may therefore be the better choice; however, it makes no difference between perfect players.)
        8. Opposite corner: If the opponent is in the corner, the player plays the opposite corner.
        9. Empty corner: The player plays in a corner square.
        10. Empty side: The player plays in a middle square on any of the 4 sides.
"""

    def __init__(self):

        #Replicate empty board matrix
        self.cols, self.rows = 3, 3
        self.boardMatrix = []
        self.aiPositions = []       #list of tuples for current ai positions
        self.playerPositions = []   #list of tuples for current player positions

    def updateBoard(self,boardView):
        #self.playerPositions.append(boardView) TODO: append latest player move
        self.boardMatrix = boardView

    def move(self):
        #win if possible
        print(self.boardMatrix)


if __name__ == '__main__':
    pass