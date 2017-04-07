# Read in the file
import os
from os.path import join, abspath, split, isfile, expanduser
from os import listdir, makedirs

def copy_replace(src, dst, old, new):

    with open(src, 'r') as file :
        s = file.read()
        s = s.replace(old, new)

    with open(dst, 'w') as file:
        file.write(s)


def listfiles(base, relpath=""):
    path = join(base, relpath)
    return [join(relpath,f) for f in listdir(path) if isfile(join(path, f))]

def flatten1(l):
    return sum(l, [])

def homedir():
    return expanduser("~")


class G4Builder:
    def __init__(self, target_dir, target_prefix, target_name=None):
        __dir__ = split(abspath(__file__))[0]
        self.template = join(__dir__, "template")
        self.files = listfiles(self.template) + listfiles(self.template, "src") + listfiles(self.template, "include")
        self.appname = "APPNAME"
        self.appprefix = "APPPREFIX"

        if target_name is None:
            self.target_name = split(target_dir)[-1]

        self.target_dir = target_dir
        self.target_prefix = target_prefix

    def run(self):
        for relfile in self.files:
            src = join(self.template, relfile)
            dst = join(self.target_dir, relfile.replace(self.appprefix, self.target_prefix))
            makedirs(split(dst)[0], exist_ok=True)
            copy_replace(src, dst, self.appname, self.target_name)
            copy_replace(dst, dst, self.appprefix, self.target_prefix)

if __name__ == "__main__":
    builder = G4Builder(target_dir=join(homedir(), "delme"), target_prefix="DM")
    builder.run()
