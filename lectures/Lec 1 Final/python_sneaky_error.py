mystery_number = 57

entry = int(input('Enter your guess for the mystery number: '))

message1 = 'Incorrect'
message2 = 'Correct! The mystery number is indeed '

if entry != mystery_number:
    print('Incorrect')
else:
    print(message2 + mystery_number)
