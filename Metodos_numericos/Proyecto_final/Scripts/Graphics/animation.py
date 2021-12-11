import moviepy.video.io.ImageSequenceClip as Movie_maker
import matplotlib.pyplot as plt
import numpy as np
import os


def mkdir(path="", name=""):
    try:
        os.mkdir("{}{}".format(path,
                               name))
    except FileExistsError:
        pass


def create_animation(path="Temp/", path_output="Output/", name="animation", delete=True, fps=10):
    """
        Funcion que ejecuta la creacion de la animacion
    """
    mkdir(path)
    filenames = sorted(os.listdir(path))
    filenames = [path+filename for filename in filenames if ".png" in filename]
    output_file = "{}{}.mp4".format(path,
                                    name)
    movie = Movie_maker.ImageSequenceClip(filenames,
                                          fps=fps,)
    movie.write_videofile(output_file,
                          logger=None)
    print("Creación del video en {}".format(path_output))
    os.system("mv {}{}.mp4 {}".format(path,
                                      name,
                                      path_output))
    if delete:
        os.system("rm {}*.png".format(path))


def plot(data: np.array, iteration: int, path="Temp/"):
    mkdir(path)
    n = len(str(np.shape(data)[0]))
    data_to_plot = data[iteration]
    min_value = np.min(data)
    max_value = np.max(data)
    plt.plot(data_to_plot)
    plt.ylim(min_value, max_value)
    plt.savefig("{}{}".format(path,
                              str(iteration).zfill(n)))
    plt.clf()


data = np.loadtxt("../Output/output.txt")
n = np.shape(data)[0]
for i in range(n):
    plot(data, i)
create_animation()
