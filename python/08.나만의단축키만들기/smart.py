from pynput.keyboard import Key,Listener,KeyCode

MY_HOT_KEYS=[
    {"function1": {Key.ctrl_l, Key.alt_1, KeyCode(char="n")}},
    {"function2": {Key.ctrl_l, Key.alt_1, KeyCode(char="b")}},
    {"function3": {Key.ctrl_l, Key.alt_1, KeyCode(char="g")}},
]

current_keys=set()
    
def function1():
    print("함수 1 호출")



def key_pressed(key):
    print("Pressed {}".format(key))
    for data in MY_HOT_KEYS:
        FUNCTION=list(data.keys())[0]
        KEYS=list(data.values())

        if key in KEYS:
            current_keys.add(key)

            if all(k in current_keys for k in KEYS):
                function = eval(FUNCTION)
                function()

def key_released(key):
    print("Released {}".format(key))

    if key in current_keys:
        current_keys.remove(key)

    if key == Key.esc:
        return False

with Listener(on_press=key_pressed, on_release=key_released) as listener:
    listener.join()