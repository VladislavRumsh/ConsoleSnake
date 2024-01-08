from flask import Flask, request
import sqlite3

app = Flask(__name__)

@app.route('/ConsoleSnakeScoreboard')
def console_snake_scoreboard():
    # Retrieving query parameters
    name = request.args.get('name')
    score = request.args.get('score')
    grid = request.args.get('grid')
    speed = request.args.get('speed')

    # Connecting to sqlite database
    connection = sqlite3.connect('ConsoleSnakeDB.db')
    cursor = connection.cursor()

    # Creating a table 'scoreboard'
    cursor.execute('''CREATE TABLE IF NOT EXISTS scoreboard (
                        id INTEGER PRIMARY KEY,
                        name TEXT NOT NULL,
                        score INTEGER NOT NULL,
                        grid TEXT NOT NULL,
                        speed INTEGER NOT NULL)''')

    # Inserting data into the table
    cursor.execute("INSERT INTO scoreboard (name, score, grid, speed) VALUES (?, ?, ?, ?)", (name, score, grid, speed))

    connection.commit()
    connection.close()

    return "Your score was added to the scoreboard!"

if __name__ == '__main__':
    app.run(debug=True, port=8123, host='0.0.0.0')
~                                                                                                                                                                                                                                                                                                                            ~                                                     