# This is the implementation of genetic algorithm to solve optimization problem
from math import sqrt, pi, floor
import random


class GeneticAlgorithm:
    #parameters
    penaltyBias = 4.2
    decimal_point = 3
    total_population = 400
    generation = 600
    mutation_rate = 0.2
    cross_over_rate = 0.4
    num_gen = 3
    max_value = 10

    def __init__(self):
        random.seed(1)
        self.execute()

    def execute(self):
        """
        structure of GA which go through each phase of GA for each generations

        :return: None
        """
        population = self.generateChromosome(self.total_population, self.num_gen, self.max_value)
        best_result = []
        last_gen = []
        for gen in range(self.generation):
            fitness = []
            for chromosome in population:
                fitness.append(GeneticAlgorithm.calcFitness(chromosome))
            fitness.sort(key=lambda x: x[0], reverse=True)
            last_gen = fitness[0].copy()

            if (len(best_result) == 0) or (last_gen[0] > best_result[0]):
                best_result = last_gen.copy()

            population = self.selection(fitness)
            population = self.cross_over(population)
            population = self.mutation(population)

        GeneticAlgorithm.decodeResult(best_result)
        GeneticAlgorithm.decodeResult(last_gen, msg="Last Generation")

    @staticmethod
    def decodeResult(fitness_object, msg="Best result"):
        """
        Decode the chromosome and obtain result
        :param fitness_object: the chromosome and pre-computed fitness value
        :param msg: basic explain on the chromosome
        :return: None
        """
        print(msg)
        print("x:", fitness_object[2][0])
        print("y:", fitness_object[2][1])
        print("z:", fitness_object[2][2])
        print("Fitness Value:", fitness_object[1])
        print("Minimum Area:", GeneticAlgorithm.FitnessFunction(fitness_object[2]))
        print("Penalty Value:", GeneticAlgorithm.PenaltyFunction(fitness_object[2]))



    @staticmethod
    def generateChromosome(n: int, size: int, limit: int):
        """
        Generate random value for chromosome based on the template on:
        -the number of locus in each chromosome
        -number of population to be generated

        :param n: the size of population
        :param size: the number of locus in each chromosome
        :param limit: the maximum value of chromosome
        :return: random generated population
        """
        population = []
        for i in range(n):
            chromosome = []
            for locus in range(size):
                chromosome.append(round(random.uniform(0, limit), GeneticAlgorithm.decimal_point))
            population.append(chromosome)

        return population

    @staticmethod
    def calcFitness(chromosome):
        """
        function to compute fitness value and factor for chromosome
        -penalty value will be added to fitness value for minimization problem

        :param chromosome: the chromosome to compute fitness value
        :return: the fitness factor, fitness value and the chromosome
        """
        try:
            if len(chromosome) != GeneticAlgorithm.num_gen:
                raise ValueError

            fitness_value = GeneticAlgorithm.FitnessFunction(chromosome) + GeneticAlgorithm.PenaltyFunction(chromosome)
            factor = GeneticAlgorithm.FitnessFactor(fitness_value)
            return [factor, fitness_value, tuple(chromosome)]

        except ValueError:
            print("Invalid Gnome Provided")
            return None

    """
    [x] = chromosome
    fitness = (x ** 2) + \
        (pi * ((10 - (4 * x)) / pi) ** 2) + \
        ((sqrt(3) / 4) * (((4 / 3) * x) ** 2))
    """

    @staticmethod
    def FitnessFunction(chromosome):
        """
        Fitness function to evaluate the chromosome to understand the difference between current result and ideal case
        -for minimization problem, the fitness value should be approach to 0

        :param chromosome: the chromosome to compute fitness value
        :return: the fitness value of chromosome
        """
        try:
            if len(chromosome) != GeneticAlgorithm.num_gen:
                raise ValueError

            [x, y, z] = chromosome
            fitness = (x ** 2) + (pi * (y ** 2)) + ((sqrt(3) / 4) * (z ** 2))
            return fitness
        except ValueError:
            print("Invalid Gnome Provided")
            return None

    @staticmethod
    def PenaltyFunction(chromosome):
        """
        Penalty function is used to limit the possible output to meet the additional constraint and objective
        -the bias can be adjusted to control the effectiveness of penalty
        -in ideal case, penalty should be 0

        :param chromosome: the chromosome to compute penalty value
        :return: the penalty value to be added on fitness value
        """
        try:
            if len(chromosome) != GeneticAlgorithm.num_gen:
                raise ValueError

            [x, y, z] = chromosome
            penalty1 = (4 * x) + (2 * pi * y) + (3 * z) - 20
            penalty2 = (4 * x) - (3 * z)
            total_penalty = round(
                                (GeneticAlgorithm.penaltyBias * max(0, abs(penalty1)) +
                                 GeneticAlgorithm.penaltyBias * max(0, abs(penalty2)))
                                , GeneticAlgorithm.decimal_point)

            return total_penalty
        except ValueError:
            print("Invalid Gnome Provided")
            return None

    @staticmethod
    def FitnessFactor(fitness_value):
        """
        get fitness value in probability (nearer to 0 means better result)


        :param fitness_value: fitness value of chromosome
        :return: fitness factor
        """
        return 1 / (1 + fitness_value)

    @staticmethod
    def selection(fitness_population):
        """
        Perform selection where a roulette is generated and cumulative probability is calculated for each chromosome
        -the population amount of pvalue is generated and
        -if pvalue drop between probability range for a chromosome, the chromosome is selected

        :param fitness_population: the current population with pre-computed fitness value and fitness factor
        :return: the new generation obtained through selection
        """
        total_fit = sum([fitness[0] for fitness in fitness_population])
        prob = []
        new_generation = []
        cumulative_prob = 0

        #compute probability
        for fitness_entity in fitness_population:
            probability = fitness_entity[0]/total_fit
            cumulative_prob += probability
            prob_entity = [probability, cumulative_prob, fitness_entity[2]]
            prob.append(prob_entity)

        for i in range(GeneticAlgorithm.total_population):
            selected = random.random()
            position = next(i for i, entity in enumerate(prob) if entity[1] > selected)
            new_generation.append(prob[position][2])

        return new_generation



    @staticmethod
    def cross_over(population):
        """
        Perform cross_over on the population
        -pvalue is generated for each chromosome
        -if pvalue larger than cross_over rate, the chromosome undergo mutation
        -chromosome will cross over with next selected chromosome

        :param population: the current population
        :return: newly generated population
        """
        population_cp = population.copy()
        parents = []
        for i, chromosome in enumerate(population_cp):
            cross_over_value = random.random()
            if cross_over_value < GeneticAlgorithm.cross_over_rate:
                parents.append([i, chromosome])

        num_parent = len(parents)
        if num_parent < 2:
            return population

        for i, entity in enumerate(parents):
            parentA = entity[1]
            parentB = parents[(i+1) % num_parent][1]
            cross_over_point = random.randint(1, GeneticAlgorithm.num_gen)
            child = parentA[:cross_over_point] + parentB[cross_over_point:]
            population_cp[entity[0]] = child

        return population_cp

    @staticmethod
    def mutation(population):
        """
        Perform mutation on the population
        -number of mutated gene is calculated based on mutation rate
        -the changes in value of gene is calculated as: (gene - mutation_rate, gene + mutation_rate)

        :param population: the current population
        :return: newly generated population
        """

        population_cp = population.copy()
        total_gene = GeneticAlgorithm.num_gen * GeneticAlgorithm.total_population
        num_mutation = total_gene * GeneticAlgorithm.mutation_rate
        mutate_pos = []

        for x in range(floor(num_mutation)):
            position = -1
            while position < 0 or position in mutate_pos:
                position = random.randint(0, total_gene)
            mutate_pos.append(position)

        for pos in mutate_pos:
            if GeneticAlgorithm.num_gen <= 1:
                value = population_cp[pos-1][0]
                new_value = value * random.uniform(1-GeneticAlgorithm.mutation_rate, 1+GeneticAlgorithm.mutation_rate)
                population_cp[pos-1] = tuple([round(new_value, GeneticAlgorithm.decimal_point)])
            else:
                chromosome = pos // GeneticAlgorithm.num_gen
                gene = pos % GeneticAlgorithm.num_gen
                value = population_cp[chromosome-1][gene]
                new_value = value * random.uniform(1 - GeneticAlgorithm.mutation_rate,
                                                   1 + GeneticAlgorithm.mutation_rate)
                ch = []
                for i in range(GeneticAlgorithm.num_gen):
                    if i != gene:
                        ch.append(population_cp[chromosome-1][i])
                    else:
                        ch.append(round(new_value, GeneticAlgorithm.decimal_point))
                population_cp[chromosome-1] = tuple(ch)

        return population_cp


if __name__ == "__main__":
    GeneticAlgorithm()
