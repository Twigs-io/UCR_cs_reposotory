import unittest
import randomgame

class TestGame(unittest.TestCase):
    def test1(self):
        answer = 5
        guess = 5
        result = randomgame.randomgames(guess, answer)
        self.assertTrue(result)
        
    def test2(self):
        answer = 5
        guess = 1
        result = randomgame.randomgames(guess, answer)
        self.assertFalse(result)
    def test3(self):
        answer = 5
        guess = 11
        result = randomgame.randomgames(guess, answer)
        self.assertFalse(result)
        
if __name__ == '__main__':
    unittest.main()