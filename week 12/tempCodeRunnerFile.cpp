   int sum = 0;
    for (i = 0; i < MAX; i++)
        if (i != startNode)
            sum += distance[i];
    cout << "Average value from startNode to all other nodes = " << sum / (MAX - 1) << endl;