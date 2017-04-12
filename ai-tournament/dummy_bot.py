# Board size
N = 20
M = 30

# Read constant input
NUMBER_OF_PLAYERS = int(raw_input())
MY_ID             = raw_input()

MOVE    = ("LEFT", "RIGHT", "UP", "DOWN")
vx      = (0, 0, -1, 1)
vy      = (-1, 1, 0, 0)

while (True):
    # Read board state
    board = []
    for i in range(N):
        board.append(raw_input())

    player = []
    # Read position of other players
    for i in range(NUMBER_OF_PLAYERS):
        position = tuple([int(x) for x in raw_input().split()])
        player.append(position)

    # This is where AI shine :3
    x, y = player[int(MY_ID) - 1]
    for i in range(4):
        if board[x + vx[i]][y + vy[i]] == MY_ID:
            print MOVE[i]
            break
