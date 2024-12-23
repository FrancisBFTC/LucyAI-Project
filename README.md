# LucyAI Project

This is an  AI model for machine learning made in C from scratch.

## How to run

First, you should train the dataset with this command line:

```batch
$> lucy --train fignet -c 2 -e 5000 -l 0.5 -d "quadrados,triangulos"
```

**--train** is the parameter that specify the model name (training data file).
**-c** is the classes ammout, **-e** is epoch, **-l** is the learning rate and **-d** is the dataset folders.

Then, you can realize the predictions:

```batch
$> lucy --pred fignet teste1.png
```

**--pred** is the parameter to predict the values, so you can pass the model name and predict with an input image.

If you want to see the neural network information, you can type:

```batch
$> lucy --info fignet output.txt
```

This way, you will save the neural network information to the output TXT file.

In soon, i will make a Documentation on a full E-book. Thanks for using the repo.
