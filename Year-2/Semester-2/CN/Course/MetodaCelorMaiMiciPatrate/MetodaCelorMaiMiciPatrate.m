image1 = imread('cat.jpeg');
image2 = imread('cat2.jpg');

imGray = rgb2gray(image1);

[mm,nn,pp] = size(imGray);
[mm2, nn2, pp2] = size(image2);

threshold = 10;
black_pixels = findBlackPixels(image1, threshold);
x = black_pixels(:, 1);
y = black_pixels(:, 2);
x = reshape(x, 1, []);
y = reshape(y, 1, []);
black_pixels2 = findBlackPixels(image2, threshold);
x2 = black_pixels2(:, 1);
y2 = black_pixels2(:, 2);
x2 = reshape(x2, 1, []);
y2 = reshape(y2, 1, []);

figure;
imshow(image1);
title('Imaginea originala');
params0 = [0, 0];
paramsOpt = fminunc(@(params) leastSquaresLine(params, x, y), params0);
mOpt = paramsOpt(1);
cOpt = paramsOpt(2);
x_line = linspace(0, mm);
y_line = mOpt * x_line + cOpt;
figure;
plot(y, x, 'bo');
axis('ij');
hold on;
plot(y_line, x_line, 'r-', 'LineWidth', 2);
legend('black pixels', 'symmetry axis');
hold off;

figure;
imshow(image2);
title('Imaginea originala');
paramsOpt2 = fminunc(@(params) leastSquaresLine(params, x2, y2), params0);
mOpt2 = paramsOpt2(1);
cOpt2 = paramsOpt2(2);
x_line2 = linspace(0, mm2);
y_line2 = mOpt2 * x_line2 + cOpt2;
figure;
plot(y2, x2, 'bo');
axis('ij');
hold on;
plot(y_line2, x_line2, 'r-', 'LineWidth', 2);
legend('pixeli negri', 'axa de simetrie');
hold off;

function cost = leastSquaresLine(params, x, y)
    m = params(1);
    c = params(2);
    
    errors = y - (m*x + c);
    
    cost = sum(errors.^2);
end

function black_pixels = findBlackPixels(image, threshold)
    if size(image, 3) == 3
        gray_image = rgb2gray(image);
    else
        gray_image = image;
    end
    

    [rows, cols] = size(gray_image);

    num_black_pixels = sum(gray_image(:) < threshold);
    black_pixels = zeros(num_black_pixels, 2);
    count = 0;

    for i = 1:rows
        for j = 1:cols
            if gray_image(i, j) < threshold
                count = count + 1;
                black_pixels(count, :) = [i, j];
            end
        end
    end

    black_pixels = black_pixels(1:count, :);
end
