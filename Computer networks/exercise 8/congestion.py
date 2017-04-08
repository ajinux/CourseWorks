print("Enter the initial threshold")

thres = int(input())

rounds = 1

cwnd = 2

while True:
    print("Enter the interupt :")
    stat = int(input())
    if stat == 1:  # time-out
        cwnd = 1
        thres = thres // 2
        print("changed threshold :", thres)
    if stat == 2:
        cwnd = cwnd // 2
        thres = thres // 2
        print("changed threshold :", thres)

    if thres > cwnd:
        if cwnd * 2 > thres:
            cwnd = thres
        else:
            cwnd = cwnd * 2
        rounds = rounds + 1
        print("Window size :", cwnd, "Rounds :", rounds, "Threshold: ", thres, " Slow Start")
    else:
        cwnd = cwnd + 1
        rounds = rounds + 1
        thres = thres + 1
        print("Window size :", cwnd, "Rounds :", rounds, "Threshold: ", thres, " Slow Start")
