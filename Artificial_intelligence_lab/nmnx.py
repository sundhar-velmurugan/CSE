def verify(numberOfMissionaries, numberOfCannibals):

    print (numberOfMissionaries, numberOfCannibals)

    if numberOfCannibals < 0 or numberOfMissionaries < 0 or numberOfCannibals > 3 or numberOfMissionaries > 3:
        return 0

    if numberOfMissionaries == 0:
        return 1

    if numberOfMissionaries < numberOfCannibals:
        return 0

    numberOfMissionaries = 3 - numberOfMissionaries
    numberOfCannibals = 3 - numberOfCannibals

    if numberOfMissionaries < numberOfCannibals:
        return 0

    return 1

directions = [ [1, 0], [2, 0], [1, 1], [0, 2], [0, 1] ]
answer = [3, 3, 1]
visited = [[3, 3, 0]]
def solve():

    queue = []
    queue.append([3, 3, 0])

    while len(queue) > 0:
        temp = queue[0]
        queue.pop(0)
        #visited.append(temp)

        print (temp)
        if temp == answer:
            return

        numberOfCannibals = temp[1]
        numberOfMissionaries = temp[0]
        boatPosition = temp[2]

        for item in directions:

            if boatPosition == 1:
                t1 = numberOfMissionaries + item[0]
                t2 = numberOfCannibals + item[1]

            else:
                t1 = numberOfMissionaries - item[0]
                t2 = numberOfCannibals - item[1]

            temp = [t1, t2, 1 - boatPosition]
            if verify(t1, t2) == 1 and temp not in visited:
                queue.append(temp)
                visited.append(temp)

solve()