#!/usr/bin/env python
# http://pythonhosted.org/pebl/tutorial.html

from pebl import data
from pebl.learner import greedy
dataset = data.fromfile("pebl-tutorial-data1.txt")
dataset.discretize()
learner = greedy.GreedyLearner(dataset)
ex1result = learner.run()
ex1result.tofile("example1-result")
