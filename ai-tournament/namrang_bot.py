#----------------------------------------------------------------#
# Board size
N = 20
M = 30
# Read constant input
NUMBER_OF_PLAYERS = int(raw_input())
MY_ID             = int(MY_VALUE) - 1
MY_VALUE          = str(int(raw_input()) * 2 - 1)
MY_UNSTABLE_VALUE = str(int(MY_VALUE) * 2)
# Move constant
MOVE    = ('LEFT', 'RIGHT', 'UP', 'DOWN')
vx      = (0, 0, -1, 1)
vy      = (-1, 1, 0, 0)
board = []
player = []
last_move = ''
#----------------------------------------------------------------#
def process():
    global last_move
    while (True):
        process_new_input()
        last_move = best_move()
        print last_move

def best_move():
    best_move = ''
    best_score = 0
    for i in range(4):
        if validMove(i):
            new_score = calculate_move(i)
            if new_score > best_score:
                best_score = new_score
                best_move = MOVE[i]
    return best_move

def calculate_move(i):
    score = 100 # initial score
    x, y = get_my_location()
    nx, ny = (x + vx[i], y + vy[i]) # new location
    val = board[nx][ny] # new value of new location
    #++++++++++++Positive++++++++++++#
    if create_unstable(val): # create new unstable cell
        score += 20
    if is_other_unstable(val): # kill other player, JUST DO IT!
        score += 500
    if is_board_have_my_unstable() and val == MY_VALUE: # create some stable cells
        score += 100
    #------------Negative------------#
    if not is_board_have_my_unstable() and val == MY_VALUE: # still in stable cells but do not create any unstable cells
        score -= 50
    if MOVE[i] == last_move:
        score -= 5 # i don't want to go to same move

    return score

#----------------------------------------------------------------#
def process_new_input():
    global board, player
    # Read board state
    board = []
    for i in range(N):
        board.append(raw_input())
    # Read position of other players
    player = []
    for i in range(NUMBER_OF_PLAYERS):
        position = tuple([int(x) for x in raw_input().split()])
        player.append(position)

def get_my_location():
    return get_player_location(MY_ID)

def get_player_location(_id):
    return player[_id]

def create_unstable(val):
    if val == MY_VALUE:
        return False
    return True

def is_other_unstable(val):
    val = int(val)
    if val == 0:
        return False
    return val % 2 == 0

def is_board_have_my_unstable():
    for i in range(N):
        if MY_UNSTABLE_VALUE in board[i]:
            return True
    return False

def validMove(i):
    x, y = get_my_location()
    # Out of grid
    if x + vx[i] < 0:
        return False
    if x + vx[i] == N:
        return False
    if y + vy[i] < 0:
        return False
    if y + vy[i] == M:
        return False
    # Go to my unstable cell
    if board[x + vx[i]][y + vy[i]] == MY_UNSTABLE_VALUE:
        return False
    # Go anti-last-move
    if i <= 1 and i >= 0:
        return last_move != MOVE[1 - i]
    if i <= 3 and i >= 2:
        return last_move != MOVE[5 - i]
    return True

process()
