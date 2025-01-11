from InquirerPy import prompt
import requests as re
import os
import json

LEETCODE_DIR = "."

LANG_FILE_EXTENSIONS = {
    "C++": ".cpp",
    "Java": ".java",
    "Python": ".py",
    "Python3": ".py",
    "C": ".c",
    "C#": ".cs",
    "JavaScript": ".js",
    "TypeScript": ".ts",
    "PHP": ".php",
    "Swift": ".swift",
    "Kotlin": ".kt",
    "Dart": ".dart",
    "Go": ".go",
    "Ruby": ".rb",
    "Scala": ".scala",
    "Rust": ".rs",
    "Racket": ".rkt",
    "Erlang": ".erl",
    "Elixir": ".ex",
}

class bcolors:
    HEADER = '\033[95m'
    OKBLUE = '\033[94m'
    OKCYAN = '\033[96m'
    OKGREEN = '\033[92m'
    WARNING = '\033[93m'
    FAIL = '\033[91m'
    ENDC = '\033[0m'
    BOLD = '\033[1m'
    UNDERLINE = '\033[4m'


def query_user():
    # Step 1: Ask for the problem name
    questions = [
        {
            "type": "input",
            "name": "problem_name",
            "message": "Enter The LeetCode Problem Title-Slug:",
        },
        {
            "type": "list",
            "name": "language",
            "message": "Select The Programming Language:",
            "choices": ["Python", "C++", "JavaScript", "Java"],
        },
    ]

    answers = prompt(questions)

    return (answers["problem_name"], answers["language"])

def get_problem_info(title_slug):

    query = """
    query {
      question(titleSlug: "%s") {
        questionId
        title
        content
        difficulty
        likes
        dislikes
        topicTags {
          name
        }
        codeSnippets {
          lang
          code
        }
      }
    }
    """ % title_slug

    response = re.post(
        "https://leetcode.com/graphql", 
        json={"query": query}
    )

    if response.status_code == 200:
        return response.json()["data"]
    else:
        return None


def create_project(title_slug, chosen_lang, problem_data):

    def getBoilerPlateCode():
        code_snippets = problem_data["codeSnippets"]
        for elem in code_snippets:
            if elem["lang"] == chosen_lang:
                return elem["code"]
        return None
        

    # Get Makefile code
    makefile_dir = "./my-makefiles"
    available_makefiles = os.listdir(makefile_dir)
    makefile_code = None
    if not (chosen_lang + ".txt" in available_makefiles):
        print(bcolors.WARNING + "No Makefile for Chosen Language, thus no makefile will be created" + bcolors.ENDC)
    else:
        with open(makefile_dir + f"/{chosen_lang}.txt", "r") as tf:
            makefile_code = tf.read()

    boiler_plate_code = getBoilerPlateCode()
    file_extension = LANG_FILE_EXTENSIONS[chosen_lang];

    quest_id = problem_data["questionId"]
    dir_name = quest_id + "-" + title_slug
    difficulty = problem_data["difficulty"]

    base_dir = LEETCODE_DIR + f"/{difficulty.lower()}/" + dir_name
    os.makedirs(base_dir, exist_ok=True)

    extra_dirs = []
    extra_dirs.append(base_dir + "/src")
    extra_dirs.append(base_dir + "/data")
    extra_dirs.append(base_dir + "/bin")

    for dir in extra_dirs:
        if not os.path.exists(dir):
            os.mkdir(dir)

    with open(base_dir + "/data/problem-info.json", "w") as tf:
        tf.write(json.dumps(problem_data, indent=4))

    with open(base_dir + "/src/main" + file_extension, "w") as tf:
        tf.write(boiler_plate_code)

    with open(base_dir + "/src/rough-notes.txt", "w") as tf:
        tf.write("\n")

    if (not makefile_code is None):
        with open(base_dir + "/Makefile", "w") as tf:
            tf.write(makefile_code)

    print(bcolors.OKGREEN + "Successfully Created Project at: " + base_dir + bcolors.ENDC)

def main():

    title_slug, chosen_lang = query_user()
    problem_data = get_problem_info(title_slug)
    if (problem_data is None) or (problem_data["question"] is None):
        error_outp = "Error Retrieving data for Problem: " + title_slug
        print(bcolors.FAIL + error_outp + bcolors.ENDC)
        return 1

    create_project(title_slug, chosen_lang, problem_data["question"])


if __name__ == "__main__":
    main()

