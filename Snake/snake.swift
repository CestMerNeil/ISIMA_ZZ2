import Spritekit

class SnakeScene: SKScene {
  let snakeSpeed = 0.1

  var snake: [SKSpriteNode] = []
  var food: SKSpriteNode?
  var direction: CGVector = CGVector(dx: 1, dy: 0)
  var snakeHead: SKSpriteNode {
    return snake.first!
  }
  var snakeTail: SKSpriteNode {
    return snake.last!
  }
  var gameOver = false

  override func didMove(to view: SKView) {
    // Set up initial snake and food
    let snakeHead = SKSpriteNode(color: .green, size: CGSize(width: 20, height: 20))
    snakeHead.position = CGPoint(x: view.frame.midX, y: view.frame.midY)
    addChild(snakeHead)
    snake.append(snakeHead)
    
    createFood()
  }
  
  override func update(_ currentTime: TimeInterval) {
    if gameOver { return }

    // Move the snake
    let newHeadPos = CGPoint(x: snakeHead.position.x + direction.dx, y: snakeHead.position.y + direction.dy)
    snakeHead.position = newHeadPos

    // Check for collision with food
    if let food = food, snakeHead.frame.intersects(food.frame) {
      snake.append(food)
      createFood()
    }

    // Check for collision with wall or self
    if isOffScreen() || snakeHead.frame.intersects(snakeTail.frame) {
      gameOver = true
      // Display game over message
    }

    // Move the rest of the snake
    for i in (1..<snake.count).reversed() {
      snake[i].position = snake[i - 1].position
    }
  }
  func isOffScreen() -> Bool {
    return snakeHead.position.x < 0 || snakeHead.position.x > size.width
      || snakeHead.position.y < 0 || snakeHead.position.y > size.height
  }
  
  func createFood() {
    let xPos = CGFloat.random(in: 0...size.width)
    let yPos = CGFloat.random(in: 0...size.height)
    let food = SKSpriteNode(color: .red, size: CGSize(width: 20, height: 20))
    food.position = CGPoint(x: xPos, y: yPos)
    addChild(food)
    self.food = food
  }
}
