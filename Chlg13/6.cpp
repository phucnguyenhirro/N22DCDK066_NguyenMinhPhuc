class TestScores:
    def __init__(self, score1=0, score2=0, score3=0):
        self._score1 = score1
        self._score2 = score2
        self._score3 = score3

    def get_score1(self):
        return self._score1

    def get_score2(self):
        return self._score2

    def get_score3(self):
        return self._score3

    def set_score1(self, score1):
        self._score1 = score1

    def set_score2(self, score2):
        self._score2 = score2

    def set_score3(self, score3):
        self._score3 = score3

    def calculate_average(self):
        return (self._score1 + self._score2 + self._score3) / 3

# Program to demonstrate the TestScores class
def main():
    # Get test scores from the user
    score1 = float(input("Enter the first test score: "))
    score2 = float(input("Enter the second test score: "))
    score3 = float(input("Enter the third test score: "))

    # Create an instance of TestScores
    scores_object = TestScores(score1, score2, score3)

    # Display the average of the scores
    average = scores_object.calculate_average()
    print("The average of the test scores is:", average)

# Run the program
if __name__ == "__main__":
    main()
