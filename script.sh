#!/bin/bash
#SBATCH --job-name=openmp_sum
#SBATCH --nodes=1
#SBATCH --ntasks=1
#SBATCH --cpus-per-task=48
#SBATCH --time=00:05:00
#SBATCH --partition=cpu
#SBATCH --output=openmp_sum_%j.out
#SBATCH --error=openmp_sum_%j.err
#SBATCH --reservation=training
# Load compiler
#module load gcc

# Set number of OpenMP threads
#export OMP_NUM_THREADS=n

# Run the program
time ./6.Assignment
