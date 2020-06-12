class KeyFrame:
    time = 0
    value = 0
    leftTangent = 0
    rightTangent = 0

    def __init__(self, t, v, l, r):
        self.time = t
        self.value = v
        self.leftTangent = l
        self.rightTangent = r


def evaluate_internal(cur_time, left_key, right_key):
    left_time = left_key.time
    left_value = left_key.value
    left_tan = left_key.rightTangent

    right_time = right_key.time
    right_value = right_key.value
    right_tan = right_key.leftTangent

    t = (cur_time - left_time) / (right_time - left_time)
    scale = right_time - left_time

    h00 = 2 * pow(t, 3) - 3 * pow(t, 2) + 1
    h10 = 1 * pow(t, 3) - 2 * pow(t, 2) + t
    h01 = -2 * pow(t, 3) + 3 * pow(t, 2)
    h11 = 1 * pow(t, 3) - 1 * pow(t, 2)

    v = h00 * left_value + h10 * scale * left_tan + h01 * right_value + h11 * scale * right_tan

    return v


