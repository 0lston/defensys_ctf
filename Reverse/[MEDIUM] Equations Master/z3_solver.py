from z3 import *

def solve_flag():
    # Create Z3 solver
    solver = Solver()

    # Define Z3 variables for each character in the flag
    flag = [BitVec(f'flag_{i}', 8) for i in range(22)]

    # Add constraints based on the check_flag function
    solver.add(flag[18] * flag[7] & flag[12] ^ flag[2] == 19)
    solver.add(flag[1] % flag[14] - flag[21] % flag[15] == 53)
    solver.add(flag[10] + flag[4] * flag[11] - flag[20] == 9141)
    solver.add(flag[19] + flag[12] * flag[0] ^ flag[16] == 6414)
    solver.add(flag[9] ^ flag[13] * flag[8] & flag[16] == 19)
    solver.add(flag[3] * flag[17] + flag[5] + flag[6] == 8107)
    solver.add(flag[21] * flag[2] ^ flag[3] ^ flag[19] == 8792)
    solver.add(flag[11] ^ flag[20] * flag[1] + flag[6] == 8037)
    solver.add(flag[7] + flag[5] - flag[18] & flag[9] == 98)
    solver.add(flag[12] * flag[8] - flag[10] + flag[4] == 11712)
    solver.add(flag[16] ^ flag[17] * flag[13] + flag[14] == 6517)
    solver.add(flag[0] * flag[15] + flag[3] == 7481)
    solver.add(flag[13] + flag[18] * flag[2] & flag[5] ^ flag[10] == 114)
    solver.add(flag[0] % flag[12] - flag[19] % flag[7] == 17)
    solver.add(flag[14] + flag[21] * flag[16] - flag[8] == 12097)
    solver.add(flag[3] + flag[17] * flag[9] ^ flag[11] == 13069)
    solver.add(flag[15] ^ flag[4] * flag[20] & flag[1] == 105)
    solver.add(flag[6] * flag[12] + flag[19] + flag[2] == 8576)
    solver.add(flag[7] * flag[5] ^ flag[10] ^ flag[0] == 6814)
    solver.add(flag[21] ^ flag[13] * flag[15] + flag[11] == 6044)
    solver.add(flag[16] + flag[20] - flag[3] & flag[9] == 2)
    solver.add(flag[18] * flag[1] - flag[4] + flag[14] == 3812)
    solver.add(flag[8] ^ flag[6] * flag[17] + flag[12] == 10273)
    solver.add(flag[11] * flag[2] + flag[15] == 8369)

    # Check if the constraints are satisfiable
    if solver.check() == sat:
        # Get the model
        model = solver.model()
        
        # Extract the flag from the model
        result = ''.join([chr(model[flag[i]].as_long()) for i in range(22)])
        
        return result
    else:
        return None

if __name__ == "__main__":
    # Solve the flag
    flag_solution = solve_flag()

    if flag_solution:
        print(f"Correct flag: {flag_solution}")
    else:
        print("No solution found.")