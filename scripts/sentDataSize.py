
import random as rand
number_size = 1024 // 8 # used units are bytes


n = 50
k = 40
t = 35
p = 15
q = 15

def calculateMessageSize(k, n, p, t, number_size):
	total = 0
	total += k
	total += k * n
	total += k * p
	total += t
	total *= number_size

	return total

def log_2(number):
	total = 0
	while number != 0:
		total += 1
		number //= 2
	return total

alice_total = calculateMessageSize(k, n, p, t, number_size)
msg = "Alice will send " + str(alice_total) + " bytes through the open channel."
print(msg)

bob_total = calculateMessageSize(t, n, q, k, number_size)
msg = "Bob will send " + str(bob_total) + " bytes through the open channel."
print(msg)

total = 0
amount_of_tests = 100
for i in range(amount_of_tests):
	tmp = 0
	for j in range(2 * n):
		tmp += rand.randint(0, 2 ** (number_size * 8)) * rand.randint(0, 2 ** (number_size * 8))
	total += tmp

total //= amount_of_tests # it's average key now
key_length = log_2(total)
msg = "The average size of key is " + str(key_length) + " bits."
print(msg)
