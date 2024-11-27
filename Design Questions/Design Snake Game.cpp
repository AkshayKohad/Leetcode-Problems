Design a Snake game that is played on a device with screen size height x width. Play the game online if you are not familiar with the game.

The snake is initially positioned at the top left corner (0, 0) with a length of 1 unit.

You are given an array food where food[i] = (ri, ci) is the row and column position of a piece of food that the snake can eat. When a snake eats a piece of food, its length and the game's score both increase by 1.

Each piece of food appears one by one on the screen, meaning the second piece of food will not appear until the snake eats the first piece of food.

When a piece of food appears on the screen, it is guaranteed that it will not appear on a block occupied by the snake.

The game is over if the snake goes out of bounds (hits a wall) or if its head occupies a space that its body occupies after moving (i.e. a snake of length 4 cannot run into itself).

Implement the SnakeGame class:

SnakeGame(int width, int height, int[][] food) Initializes the object with a screen of size height x width and the positions of the food.
int move(String direction) Returns the score of the game after applying one direction move by the snake. If the game is over, return -1.
 

Example 1:


Input
["SnakeGame", "move", "move", "move", "move", "move", "move"]
[[3, 2, [[1, 2], [0, 1]]], ["R"], ["D"], ["R"], ["U"], ["L"], ["U"]]
Output
[null, 0, 0, 1, 1, 2, -1]

Explanation
SnakeGame snakeGame = new SnakeGame(3, 2, [[1, 2], [0, 1]]);
snakeGame.move("R"); // return 0
snakeGame.move("D"); // return 0
snakeGame.move("R"); // return 1, snake eats the first piece of food. The second piece of food appears at (0, 1).
snakeGame.move("U"); // return 1
snakeGame.move("L"); // return 2, snake eats the second food. No more food appears.
snakeGame.move("U"); // return -1, game over because snake collides with border
 

Constraints:

1 <= width, height <= 104
1 <= food.length <= 50
food[i].length == 2
0 <= ri < height
0 <= ci < width
direction.length == 1
direction is 'U', 'D', 'L', or 'R'.
At most 104 calls will be made to move.





class SnakeGame {
public:
    int snake_len;
    vector<pair<int,int>>snake_body;
    int board_height;
    int board_width;
    vector<pair<int,int>>food_position;
    int cur_food_position;
    SnakeGame(int width, int height, vector<vector<int>>& food) {
        snake_len = 1;
        snake_body.push_back({0,0});
        board_height = height;
        board_width = width;
        cur_food_position = 0;
        for(int i=0;i<food.size();i++){
            food_position.push_back({food[i][0],food[i][1]});
        }
    }
    bool check_boundary(int x,int y){
        if(x<0 || y<0 || x>=board_height || y>=board_width)return false;

        return true;
    }
    bool check_snake_body(int x,int y){
        for(int i=1;i<snake_len;i++){
            if(snake_body[i].first == x && snake_body[i].second == y)return false;
        }
        return true;
    }
   
    int move(string direction) {
        int last_x = snake_body[snake_len-1].first;
        int last_y = snake_body[snake_len-1].second;

        for(int i = snake_len-1; i>0; i--){
        snake_body[i] = snake_body[i-1];
       }
        int curx = snake_body[0].first;
        int cury = snake_body[0].second;

        if(direction=="R"){
            cury = cury+1;
        }else if(direction == "L"){
            cury = cury-1;
        }else if(direction == "D"){
            curx = curx+1;
        }else{
            curx = curx-1;
        }
        
        if(!check_boundary(curx,cury))return -1;
        if(!check_snake_body(curx,cury))return -1;
       
        cout<<curx<<" "<<cury<<endl;
        if(cur_food_position < food_position.size() && curx == food_position[cur_food_position].first && cury == food_position[cur_food_position].second){
            snake_body.push_back({last_x,last_y});
            snake_len++;
            cur_food_position++;
        }
        snake_body[0] = {curx,cury};
       
        return cur_food_position;

    }
};

/**
 * Your SnakeGame object will be instantiated and called as such:
 * SnakeGame* obj = new SnakeGame(width, height, food);
 * int param_1 = obj->move(direction);
 */
