using System;

namespace P._11.c_
{
    class Program
    {
        static void Main(string[] args)
        {
            string userInput;
            int cpuNum;
            string again = "y";
            Random num = new Random();

            Console.WriteLine("Welcome to Rock, Scissor, Papper Game!");

            while (again == "y")
            {
                int userScore = 0, cpuScore = 0;
                while ((userScore < 3) && (cpuScore < 3))
                {
                    Console.WriteLine("Choose one (Rock, Scissors, Paper): ");
                    userInput = Console.ReadLine().ToLower();
                    cpuNum = num.Next(1, 4);

                    switch (cpuNum)
                    {
                        case 1:
                            Console.WriteLine("CPU: Rock");
                            if (userInput == "rock")
                            {
                                Console.WriteLine("Same!");
                            }
                            else if (userInput == "paper")
                            {
                                Console.WriteLine("You Are a Winner!");
                                userScore++;
                            }
                            else
                            {
                                Console.WriteLine("You Lose!");
                                cpuScore++;
                            }
                            break;

                        case 2:
                            Console.WriteLine("CPU: Scissors");
                            if (userInput == "scissor")
                            {
                                Console.WriteLine("Same!");
                            }
                            else if (userInput == "rock")
                            {
                                Console.WriteLine("You Are a Winner!");
                                userScore++;
                            }
                            else
                            {
                                Console.WriteLine("You Lose!");
                                cpuScore++;
                            }
                            break;

                        case 3:
                            Console.WriteLine("CPU: Paper");
                            if (userInput == "paper")
                            {
                                Console.WriteLine("Same!");
                            }
                            else if (userInput == "scissor")
                            {
                                Console.WriteLine("You Are a Winner!");
                                userScore++;
                            }
                            else
                            {
                                Console.WriteLine("You Lose!");
                                cpuScore++;
                            }
                            break;
                    }
                }
                Console.WriteLine($"Your Score is {userScore}, CPU Score is {cpuScore}.");
                Console.WriteLine("Do you wand to play again (Y, N): ");
                again = Console.ReadLine().ToLower();
            }
        }
    }
}
