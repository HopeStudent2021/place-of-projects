import colors
# параметры основного окна
screen_width = 1280
screen_height = 902
# фоновое изображение
background_image = 'Blue.jpg'

frame_rate = 60
# параметры кирпичей
row_count = 4
brick_width = 100
brick_height = 80
brick_color = colors.RED2
offset_y = brick_height + 1
# параметры мяча
ball_speed = 8
ball_radius = 15
ball_color = colors.LAWNGREEN
# параметры ракетки
paddle_width = 200
paddle_height = 100
paddle_color = colors.ORCHID
paddle_speed = 12

status_offset_y = 5

text_color = colors.YELLOW1
initial_lives = 3
lives_right_offset = 220
lives_offset = screen_width - lives_right_offset
score_offset = 5

font_name = 'Arial'
font_size = 60

effect_duration = 20


message_duration = 1
# цвет кнопок
button_text_color = colors.WHITE,
button_normal_back_color = colors.EMERALDGREEN
button_hover_back_color = colors.FLESH
button_pressed_back_color = colors.DARKGOLDENROD2

# расположение кнопок
menu_offset_x = 20
menu_offset_y = 450
menu_button_w = 170
menu_button_h = 80

pause_ball = 2
