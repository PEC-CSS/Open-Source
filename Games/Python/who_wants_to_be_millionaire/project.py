# project.py
import tkinter as tk
from tkinter import *

def load_questions():
    return [
        ['How many sides does a triangle have?', ['2', '3', '4', '5', [2]]],
        ['Which ocean is the largest?', ['Atlantic', 'Pacific', 'Indian', 'Arctic', [2]]],
        ['What is the capital of Australia?', ['Sydney', 'Melbourne', 'Canberra', 'Perth', [3]]],
        ['Who painted the Mona Lisa?', ['Van Gogh', 'Picasso', 'Da Vinci', 'Monet', [3]]],
        ['What is the smallest country in the world?', ['Monaco', 'Vatican City', 'San Marino', 'Liechtenstein', [2]]],
        ['Which element has the atomic number 1?', ['Helium', 'Hydrogen', 'Oxygen', 'Carbon', [2]]],
        ['In which year did the Berlin Wall fall?', ['1987', '1989', '1991', '1993', [2]]],
        ['What is the longest river in the world?', ['Amazon', 'Nile', 'Yangtze', 'Mississippi', [2]]],
        ['Which composer wrote "The Four Seasons"?', ['Bach', 'Mozart', 'Beethoven', 'Vivaldi', [4]]],
        ['What is the rarest naturally occurring element on Earth?', ['Francium', 'Astatine', 'Technetium', 'Promethium', [2]]]
    ]

def calculate_winnings(question_number, is_correct, current_winnings):
    money_levels = [1000, 2000, 3000, 5000, 10000, 20000, 40000, 100000, 300000, 1000000]
    safe_levels = {2: 2000, 4: 10000, 7: 100000}
    
    if is_correct and question_number < len(money_levels):
        return money_levels[question_number]
    elif not is_correct:
        last_safe = 0
        for question_num, amount in safe_levels.items():
            if question_number >= question_num:
                last_safe = amount
        return last_safe
    else:
        return current_winnings

def validate_answer(selected_option, correct_option):
    if selected_option == 0:
        return None  # No selection made
    return selected_option == correct_option

def format_currency(amount):
    return f"${amount:,}"

class MillionaireGame:
    def __init__(self, root):
        self.root = root
        self.root.title("Who Wants to Be a Millionaire")
        self.root.geometry("900x700")
        self.root.configure(bg='#000033')

        self.questions = load_questions()
        self.current_question = 0
        self.winning_amount = 0
        self.selected_option = tk.IntVar()
        
        self.setup_ui()
        self.show_welcome()
    
    def setup_ui(self):
        self.main_frame = tk.Frame(self.root, bg='#000033')
        self.main_frame.pack(fill='both', expand=True, padx=20, pady=20)
        
        self.title_label = tk.Label(self.main_frame, text="WHO WANTS TO BE A MILLIONAIRE?", 
                                   font=('Arial', 24, 'bold'), fg='#FFD700', bg='#000033')
        self.title_label.pack(pady=20)
        
        self.game_frame = tk.Frame(self.main_frame, bg='#000033')
        self.game_frame.pack(fill='both', expand=True)
        
        self.winnings_label = tk.Label(self.game_frame, text="Current Winnings: $0",
                                      font=('Arial', 16, 'bold'), fg='#00FF00', bg='#000033')
        self.winnings_label.pack(pady=10)

        self.question_frame = tk.Frame(self.game_frame, bg='#000066', relief='raised', bd=3)
        self.question_frame.pack(fill='x', pady=20)
        
        self.question_label = tk.Label(self.question_frame, text="", font=('Arial', 14, 'bold'), 
                                      fg="#F1EBEB", bg='#000066', wraplength=500, justify='center')
        self.question_label.pack(pady=20)
        
        self.options_frame = tk.Frame(self.game_frame, bg='#000033')
        self.options_frame.pack(fill='x', pady=20)
        
        self.option_buttons = []
        for i in range(4):
            btn = tk.Radiobutton(self.options_frame, text="", variable=self.selected_option, 
                               value=i+1, font=('Arial', 12), fg='#FFFFFF', bg='#000066', 
                               selectcolor='#FFD700', activebackground='#000099',
                               activeforeground='#FFFFFF', width=50, height=2, indicatoron=False)
            btn.pack(pady=5, fill='x')
            self.option_buttons.append(btn)
        
        self.control_frame = tk.Frame(self.game_frame, bg='#000033')
        self.control_frame.pack(pady=20)
        
        self.submit_btn = tk.Button(self.control_frame, text="Final Answer", command=self.submit_answer,
                                   font=('Arial', 14, 'bold'), bg='#FFD700', fg='#000033', 
                                   width=15, height=2)
        self.submit_btn.pack(side='left', padx=10)
        
        self.quit_btn = tk.Button(self.control_frame, text="Take Money & Quit", command=self.quit_game,
                                 font=('Arial', 14, 'bold'), bg='#FF6600', fg='#FFFFFF', 
                                 width=18, height=2)
        self.quit_btn.pack(side='left', padx=10)

        self.welcome_frame = tk.Frame(self.game_frame, bg='#000033')
        
    def show_welcome(self):
        self.hide_game_elements()
        self.welcome_frame.pack(fill='both', expand=True)
        
        welcome_text = """
Welcome to 'Who Wants to Be a Millionaire'!

🎯 Answer 10 questions correctly to win 1 Million Dollars

💰 Safe levels at questions 3, 5, and 8
   (You won't lose money below these levels)

📝 Rules:
   • Select your answer and click 'Final Answer'
   • You can quit anytime and keep your winnings
   • Wrong answer drops you to last safe level

Good Luck! 🍀
        """
        
        welcome_label = tk.Label(self.welcome_frame, text=welcome_text, font=('Arial', 14),
                                fg='#FFFFFF', bg='#000033', justify='center')
        welcome_label.pack(expand=True)
        
        start_btn = tk.Button(self.welcome_frame, text="START GAME", command=self.start_game,
                             font=('Arial', 18, 'bold'), bg='#00FF00', fg='#000033', 
                             width=20, height=3)
        start_btn.pack(pady=20)
    
    def start_game(self):
        self.welcome_frame.pack_forget()
        self.show_game_elements()
        self.display_question()
    
    def hide_game_elements(self):
        self.winnings_label.pack_forget()
        self.question_frame.pack_forget()
        self.options_frame.pack_forget()
        self.control_frame.pack_forget()
    
    def show_game_elements(self):
        self.winnings_label.pack(pady=10)
        self.question_frame.pack(fill='x', pady=20)
        self.options_frame.pack(fill='x', pady=20)
        self.control_frame.pack(pady=20)
    
    def update_winnings_display(self):
        self.winnings_label.configure(text=f"Current Winnings: {format_currency(self.winning_amount)}")
    
    def display_question(self):
        if self.current_question >= 10:
            self.show_final_result(True)
            return
        
        self.update_winnings_display()
        
        question_data = self.questions[self.current_question]
        question_text = f"Question {self.current_question + 1}: {question_data[0]}"
        self.question_label.configure(text=question_text)
        
        for i, btn in enumerate(self.option_buttons):
            btn.configure(text=f"{chr(65+i)}. {question_data[1][i]}")
        
        self.selected_option.set(0)
        self.submit_btn.configure(state='normal')
        
        if self.current_question > 0:
            self.quit_btn.configure(state='normal')
        else:
            self.quit_btn.configure(state='disabled')
    
    def submit_answer(self):
        correct_option = self.questions[self.current_question][1][4][0]
        selected = self.selected_option.get()
        
        validation_result = validate_answer(selected, correct_option)
        
        if validation_result is None:
            self.question_label.configure(text="Please select an answer!", fg='#FF0000')
            return
        
        self.submit_btn.configure(state='disabled')
        self.quit_btn.configure(state='disabled')
        
        if validation_result:
            self.winning_amount = calculate_winnings(self.current_question, True, self.winning_amount)
            self.question_label.configure(
                text=f"Correct! You've won {format_currency(self.winning_amount)}!", 
                fg='#00FF00'
            )
            self.current_question += 1
            
            if self.current_question < 10:
                self.root.after(2000, self.ask_continue)
            else:
                self.root.after(2000, lambda: self.show_final_result(True))
        else:
            correct_answer = self.questions[self.current_question][1][correct_option-1]
            self.question_label.configure(
                text=f"Wrong! Correct answer: {chr(64+correct_option)}. {correct_answer}",
                fg='#FF0000'
            )
            
            self.winning_amount = calculate_winnings(self.current_question, False, self.winning_amount)
            self.root.after(3000, lambda: self.show_final_result(False))
    
    def ask_continue(self):
        if self.current_question > 1: 
            self.question_label.configure(
                text=f"You have {format_currency(self.winning_amount)}. Continue to next question?", 
                fg='#FFD700'
            )

            continue_btn = tk.Button(self.control_frame, text="Continue", command=self.continue_game,
                                   font=('Arial', 14, 'bold'), bg='#00FF00', fg='#000033', 
                                   width=12, height=2)
            continue_btn.pack(side='left', padx=5)
            
            quit_now_btn = tk.Button(self.control_frame, text="Take Money", 
                                   command=lambda: self.show_final_result(False),
                                   font=('Arial', 14, 'bold'), bg='#FF6600', fg='#FFFFFF', 
                                   width=12, height=2)
            quit_now_btn.pack(side='left', padx=5)
            
            self.submit_btn.pack_forget()
            self.quit_btn.pack_forget()
        else:
            self.continue_game()
    
    def continue_game(self):
        for widget in self.control_frame.winfo_children():
            if widget not in [self.submit_btn, self.quit_btn]:
                widget.destroy()
        
        self.submit_btn.pack(side='left', padx=10)
        self.quit_btn.pack(side='left', padx=10)
        
        self.display_question()
    
    def quit_game(self):
        self.question_label.configure(
            text=f"Are you sure you want to quit with {format_currency(self.winning_amount)}?", 
            fg='#FFD700'
        )

        yes_btn = tk.Button(self.control_frame, text="Yes, Quit", 
                          command=lambda: self.show_final_result(False),
                          font=('Arial', 12, 'bold'), bg='#FF0000', fg='#FFFFFF', width=10)
        yes_btn.pack(side='left', padx=5)
        
        no_btn = tk.Button(self.control_frame, text="No, Continue", command=self.cancel_quit,
                          font=('Arial', 12, 'bold'), bg='#00FF00', fg='#000033', width=12)
        no_btn.pack(side='left', padx=5)

        self.submit_btn.pack_forget()
        self.quit_btn.pack_forget()
    
    def cancel_quit(self):
        for widget in self.control_frame.winfo_children():
            if widget not in [self.submit_btn, self.quit_btn]:
                widget.destroy()

        self.submit_btn.pack(side='left', padx=10)
        self.quit_btn.pack(side='left', padx=10)
        
        self.display_question()
    
    def show_final_result(self, won_all):
        self.hide_game_elements()
        
        result_frame = tk.Frame(self.game_frame, bg='#000033')
        result_frame.pack(fill='both', expand=True)
        
        if won_all:
            title_text = "🎉 CONGRATULATIONS! 🎉"
            message_text = f"You've answered all 10 questions correctly!\nYou've won the maximum prize of {format_currency(self.winning_amount)}!"
            title_color = '#FFD700'
        else:
            title_text = "🎮 GAME OVER 🎮"
            message_text = f"Thank you for playing!\nYou've answered {self.current_question} questions correctly.\nYou're taking home {format_currency(self.winning_amount)}!"
            title_color = '#FF6600'
        
        result_title = tk.Label(result_frame, text=title_text, font=('Arial', 20, 'bold'),
                               fg=title_color, bg='#000033')
        result_title.pack(pady=30)
        
        result_message = tk.Label(result_frame, text=message_text, font=('Arial', 16),
                                 fg='#FFFFFF', bg='#000033', justify='center')
        result_message.pack(pady=20)

        button_frame = tk.Frame(result_frame, bg='#000033')
        button_frame.pack(pady=30)
        
        exit_btn = tk.Button(button_frame, text="EXIT", command=self.root.quit,
                           font=('Arial', 14, 'bold'), bg='#FF0000', fg='#FFFFFF', 
                           width=15, height=2)
        exit_btn.pack(padx=10)

def main():
    root = tk.Tk()
    game = MillionaireGame(root)
    root.mainloop()

if __name__ == "__main__":
    main()